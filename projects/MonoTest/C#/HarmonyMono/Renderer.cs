using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Harmony
{
    public struct Resolution
    {
        UInt16 Width;
        UInt16 Height;
        public enum Type
        {
            FullScale,
            HalfScale,
            QuarterScale,
            EighthScale,
            SixteenthScale,
            Custom
        };

    };
    public enum AttachmentType
    {
        UnknownAttachmentType = 1,
        RGBA8 = 2,
        RGBA16F = 4,
        RGBA32F = 8,
        RGBA = RGBA8 | RGBA16F | RGBA32F,
        Depth16F = 16,
        Depth24F = 32,
        Depth32F = 64,
        Depth = Depth16F | Depth24F | Depth32F

    };

    public struct Mesh
    {
        public IntPtr Handle;
    }

    public struct TextureAsset
    {
        public IntPtr Handle;
    }

    public struct Framebuffer
    {
        public IntPtr Handle;
    }

    public struct ShaderStage
    {
        public IntPtr Handle;
    }

    public struct ShaderProgram
    {
        public IntPtr Handle;
    }

    public struct NativeShaderDataSource
    {
        public IntPtr NativeHandle;
    }

    public class ShaderDataSource
    {
        public NativeShaderDataSource NativeHandle;
    }

    public class DeferredDataSource : ShaderDataSource
    {
       
    }

    public class TextureAssetSource : ShaderDataSource
    {
    }

    public struct NativePipelineStage
    {
        public IntPtr Handle;
    }

    public class PipelineStage
    {
        public NativePipelineStage NativeHandle;
    }

    public class PipelineDrawStage : PipelineStage
    {
    }

    public class DrawScreenTextureStage : PipelineStage
    {
        
    }

    public struct NativePipelineStageRenderer
    {
        public IntPtr Handle;
    }

    public class PipelineStageRenderer
    {
        public NativePipelineStageRenderer NativeHandle;
    }

    public class ScreenQuadRenderer : PipelineStageRenderer
    {
    }

    public struct Pipeline
    {
        public IntPtr Handle;
    }

    public struct View
    {
        public IntPtr Handle;
    }

    public static class Renderer
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static View GetView(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static ShaderStage BuildShader(string name, ShaderStage vert, ShaderStage frag);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Pipeline GetViewPipeline(View view);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static ShaderProgram GetShader(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativeShaderDataSource GetShaderDataSource(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativePipelineStage GetPipelineStage(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativePipelineStageRenderer GetPipelineStageRenderer(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Framebuffer PipelineAddFramebuffer(this Pipeline pipeline , string name, AttachmentType[] attachments, Resolution.Type resolutionType);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Framebuffer PipelineSetOutputFramebuffer(this Pipeline pipeline, Framebuffer fb);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void PipelineAddStage(this Pipeline pipeline, Framebuffer fb, PipelineStage stage);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void PipelineStageAddDataSource(this NativePipelineStage pipeline, NativeShaderDataSource source);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativePipelineStage CreatePipelineDrawStage(string name, ShaderProgram shader, NativePipelineStageRenderer renderer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativePipelineStageRenderer CreateScreenQuadRenderer();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativeShaderDataSource CreateDeferredDataSource(Framebuffer fb);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativeShaderDataSource CreateTextureAssetSource(ushort samplerIndex, string uniformName, TextureAsset texture);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativePipelineStage CreateDrawScreenTextureStage(ShaderProgram shader, AttachmentType attachmentType, Framebuffer[] framebuffers);
    }
}
