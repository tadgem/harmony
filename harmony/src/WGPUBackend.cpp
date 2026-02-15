#include "WGPUBackend.h"
#include <iostream>
#include "STL.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_wgpu.h"

#include <webgpu/webgpu_cpp.h>
#include <dawn/native/DawnNative.h>
#include <dawn/dawn_proc.h>

void request_adapter_callback(
  WGPURequestAdapterStatus status,
  WGPUAdapter adapter,
  WGPUStringView message, WGPU_NULLABLE void* userdata1, WGPU_NULLABLE void* userdata2
)
{
  harmony::WGPUBackend* b = static_cast<harmony::WGPUBackend*>(userdata1);

  b->wgpu_adapter = adapter;


  bool* _waitAdapter = static_cast<bool*>(userdata2);
  *_waitAdapter = false;

}

void request_device_callback(
  WGPURequestDeviceStatus status,
  WGPUDevice device,
  WGPUStringView message, WGPU_NULLABLE void* userdata1, WGPU_NULLABLE void* userdata2
)
{
  harmony::WGPUBackend* b = static_cast<harmony::WGPUBackend*>(userdata1);

  b->wgpu_device = device;

  bool* _waitDevice = static_cast<bool*>(userdata2);
  *_waitDevice = false;

}

void init2()
{
  dawnProcSetProcs(&dawn::native::GetProcs());

    // ----------------------------------------------------------------
    // 2. Initialize the Dawn Native Instance.
    // This object manages the physical connection to GPUs.
    // ----------------------------------------------------------------
    dawn::native::Instance instance;

    // ----------------------------------------------------------------
    // 3. Select a Physical Adapter (GPU).
    // Dawn Native gives us a list of specialized native adapters.
    // ----------------------------------------------------------------
    std::vector<dawn::native::Adapter> nativeAdapters = instance.EnumerateAdapters();

    // For this example, we simply pick the first available adapter.
    // In a real app, you would loop through 'nativeAdapters' and check
    // properties (like backend type or generic/discrete GPU).
    dawn::native::Adapter& selectedNativeAdapter = nativeAdapters[0];

    // Get the standard WebGPU adapter handle from the native wrapper
    wgpu::Adapter adapter = wgpu::Adapter::Acquire(selectedNativeAdapter.Get());

    wgpu::AdapterInfo properties;
    adapter.GetInfo(&properties);

    // ----------------------------------------------------------------
    // 4. Create the Logical Device.
    // ----------------------------------------------------------------
    wgpu::DeviceDescriptor deviceDesc = {};

    // CreateDevice returns a raw C WGPUDevice, so we wrap it using Acquire.
    wgpu::Device device = wgpu::Device::Acquire(selectedNativeAdapter.CreateDevice(&deviceDesc));

    if (!device) {
        std::cerr << "Failed to create device." << std::endl;
    }

    std::cout << "Dawn initialized successfully!" << std::endl;
}

void harmony::WGPUBackend::init()
{
  wgpu_instance = wgpuCreateInstance(NULL);

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("HARMONY", 1600, 900, SDL_WINDOW_RESIZABLE);
  wgpu_surface = SDL_GetWGPUSurface(wgpu_instance, window);

  WGPURequestAdapterOptions opt = {};
#ifdef WIN32
  opt.backendType = WGPUBackendType_D3D11;
#endif
  WGPURequestAdapterCallbackInfo adapter_cb = {};
  adapter_cb.nextInChain = 0;
  adapter_cb.mode = WGPUCallbackMode_AllowProcessEvents;
  adapter_cb.callback = request_adapter_callback;
  adapter_cb.userdata1 = this;
  adapter_cb.userdata2 = &_waitingAdapter;

  auto f = wgpuInstanceRequestAdapter(wgpu_instance, &opt, adapter_cb);

  WGPUFutureWaitInfo fi;
  fi.future = f;
  fi.completed = false;
  while (_waitingAdapter)
  {
    wgpuInstanceWaitAny(wgpu_instance, 1, &fi, UINT64_MAX);
  }

  assert(wgpu_adapter && "Expected WGPU Adapater to be created");

#ifndef __EMSCRIPTEN__
  WGPULimits supportedLimits = {};
  supportedLimits.nextInChain = nullptr;
#endif

#ifdef WEBGPU_BACKEND_DAWN
  bool success = wgpuAdapterGetLimits(wgpu_adapter, &supportedLimits) == WGPUStatus_Success;
#else
  bool success = wgpuAdapterGetLimits(wgpu_adapter, &supportedLimits);
#endif

  // Call the function a first time with a null return address, just to get
  // the entry count.
  WGPUSupportedFeatures supportedFeatures = {};
  wgpuAdapterGetFeatures(wgpu_adapter, &supportedFeatures);

  WGPUAdapterInfo properties = {};
  wgpuAdapterGetInfo(wgpu_adapter, &properties);


  WGPUQueueDescriptor wgpuQueueDescriptor = {};
  wgpuQueueDescriptor.label = WGPUStringView{ "Default Queue"};
  wgpuQueueDescriptor.nextInChain = nullptr;

  WGPUDeviceDescriptor wgpu_device_descriptor = {};
  wgpu_device_descriptor.requiredFeatures = supportedFeatures.features;
  wgpu_device_descriptor.requiredFeatureCount = supportedFeatures.featureCount;
  wgpu_device_descriptor.requiredLimits = &supportedLimits;
  wgpu_device_descriptor.defaultQueue = wgpuQueueDescriptor;
  wgpu_device_descriptor.label = WGPUStringView { "GPU Device" };

  WGPURequestDeviceCallbackInfo device_cb = {};
  device_cb.nextInChain = 0;
  device_cb.mode = WGPUCallbackMode_AllowProcessEvents;
  device_cb.callback = request_device_callback;
  device_cb.userdata1 = this;
  device_cb.userdata2 = &_waitingDevice;
  wgpuAdapterRequestDevice(wgpu_adapter, &wgpu_device_descriptor, device_cb);

  while (_waitingDevice) {}

  assert(wgpu_device && "Failed to acquire an appropriate device");
  _should_run = true;
}

void harmony::WGPUBackend::pre_frame() {
  SDL_Event event = {};
  while (SDL_PollEvent(&event))
    if (event.type == SDL_EVENT_QUIT)
    {
      _should_run = false;
    }

}

void harmony::WGPUBackend::end_frame() {

}

void harmony::WGPUBackend::cleanup() {
  wgpuAdapterRelease(wgpu_adapter);

  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool harmony::WGPUBackend::should_run() {
  return _should_run;
}
