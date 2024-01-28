using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;
using static Harmony.bgfx;

namespace Harmony
{
#pragma warning disable CS0169
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
        public readonly NativeShaderDataSource NativeHandle;

        public ShaderDataSource(NativeShaderDataSource nativeHandle)
        {
            NativeHandle = nativeHandle;
        }

        public static implicit operator NativeShaderDataSource(ShaderDataSource s) => s.NativeHandle;
    }

    public class DeferredDataSource : ShaderDataSource
    {
        public DeferredDataSource(NativeShaderDataSource native) : base(native)
        {
        }
    }

    public class TextureAssetSource : ShaderDataSource
    {
        public TextureAssetSource(NativeShaderDataSource native) : base(native)
        {

        }
    }

    public class BlinnPhongDataSource : ShaderDataSource
    {
        internal BlinnPhongDataSource(NativeShaderDataSource native) : base(native)
        {

        }
    }

    public struct NativePipelineStage
    {
        public IntPtr Handle;
    }

    public class PipelineStage
    {
        public readonly NativePipelineStage NativeHandle;

        internal PipelineStage(NativePipelineStage nativeHandle)
        {
            NativeHandle = nativeHandle;
        }

        public static implicit operator NativePipelineStage(PipelineStage p) => p.NativeHandle;

        public void AddShaderDataSource(NativeShaderDataSource nativeShaderDataSource)
        {
            NativeHandle.AddDataSource(nativeShaderDataSource);
        }

    }

    public class PipelineDrawStage : PipelineStage
    {
        internal PipelineDrawStage(NativePipelineStage native) : base(native)
        {
        }
    }

    public class DrawScreenTextureStage : PipelineStage
    {
        internal DrawScreenTextureStage(NativePipelineStage native) : base(native)
        {
        }
    }

    public class SkyStage : PipelineStage
    {
        internal SkyStage(NativePipelineStage native) : base(native)
        {
        }
    }

    public class DebugDrawStage : PipelineStage
    {
        internal DebugDrawStage(NativePipelineStage native) : base(native)
        {
        }
    }

    public class VectorGraphicsStage : PipelineStage
    {
        internal VectorGraphicsStage(NativePipelineStage native) : base(native)
        {
        }
    }

    public struct NativePipelineStageRenderer
    {
        public IntPtr Handle;
    }

    public class PipelineStageRenderer
    {
        public readonly NativePipelineStageRenderer NativeHandle;

        public PipelineStageRenderer(NativePipelineStageRenderer native)
        {
            NativeHandle = native;
        }

        public static implicit operator NativePipelineStageRenderer(PipelineStageRenderer r) => r.NativeHandle;

    }

    public class ScreenQuadRenderer : PipelineStageRenderer
    {
        public ScreenQuadRenderer(NativePipelineStageRenderer native) : base(native)
        {
        }
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
        public extern static Pipeline GetViewPipeline(View view);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static ShaderProgram GetShader(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativePipelineStageRenderer GetPipelineStageRendererInternal(string name);

        public static PipelineStageRenderer GetPipelineStageRenderer(string name)
        {
            NativePipelineStageRenderer nativePipelineStageRenderer = GetPipelineStageRendererInternal(name);
            if (nativePipelineStageRenderer.Handle == IntPtr.Zero)
            {
                return default;
            }

            return new PipelineStageRenderer(nativePipelineStageRenderer);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Framebuffer AddFramebuffer(this Pipeline pipeline, string name, AttachmentType[] attachments, Resolution.Type resolutionType);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Framebuffer SetOutputFramebuffer(this Pipeline pipeline, Framebuffer fb);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void AddStage(this Pipeline pipeline, Framebuffer fb, NativePipelineStage stage);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void AddDataSource(this NativePipelineStage pipeline, NativeShaderDataSource source);

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativePipelineStage CreatePipelineDrawStageInternal(string name, ShaderProgram shader, NativePipelineStageRenderer renderer);

        public static PipelineDrawStage CreatePipelineDrawStage(string name, ShaderProgram shader, PipelineStageRenderer renderer)
        {
            NativePipelineStage stage = CreatePipelineDrawStageInternal(name, shader, renderer);
            if (stage.Handle == IntPtr.Zero)
            {
                return default;
            }
            return new PipelineDrawStage(stage);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativePipelineStage CreateDrawScreenTextureStageInternal(this Pipeline pipeline, ShaderProgram shader, AttachmentType attachmentType, Framebuffer[] framebuffers);

        public static DrawScreenTextureStage CreateDrawScreenTextureStage(this Pipeline pipeline, ShaderProgram shader, AttachmentType attachmentType, Framebuffer[] framebuffers)
        {
            NativePipelineStage stage = CreateDrawScreenTextureStageInternal(pipeline, shader, attachmentType, framebuffers);
            if (stage.Handle == IntPtr.Zero)
            {
                return default;
            }
            return new DrawScreenTextureStage(stage);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativePipelineStage CreateSkyStageInternal();

        public static SkyStage CreateSkyStage()
        {
            NativePipelineStage stage = CreateSkyStageInternal();
            if(stage.Handle == IntPtr.Zero)
            {
                return default;
            }
            return new SkyStage(stage);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativePipelineStage CreateDebugDrawStageInternal(DebugDrawChannel channel);

        public static DebugDrawStage CreateDebugDrawStage(DebugDrawChannel channel)
        {
            NativePipelineStage stage = CreateDebugDrawStageInternal(channel);
            if (stage.Handle == IntPtr.Zero)
            {
                return default;
            }
            return new DebugDrawStage(stage);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativePipelineStage CreateVectorGraphicsStageInternal(VectorGraphics.Layer layer);

        public static VectorGraphicsStage CreateVectorGraphicsStage(VectorGraphics.Layer layer)
        {
            NativePipelineStage stage = CreateVectorGraphicsStageInternal(layer);
            if (stage.Handle == IntPtr.Zero)
            {
                return default;
            }
            return new VectorGraphicsStage(stage);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativePipelineStageRenderer CreateScreenQuadRendererInternal();

        public static ScreenQuadRenderer CreateScreenQuadRenderer()
        {
            NativePipelineStageRenderer nativePipelineStageRenderer = CreateScreenQuadRenderer();
            if (nativePipelineStageRenderer.Handle == IntPtr.Zero)
            {
                return default;
            }

            return new ScreenQuadRenderer(nativePipelineStageRenderer);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativeShaderDataSource CreateDeferredDataSourceInternal(this Pipeline pipeline, Framebuffer fb);

        public static DeferredDataSource CreateDeferredDataSource(this Pipeline pipeline, Framebuffer fb)
        {
            NativeShaderDataSource nativeShaderDataSource = CreateDeferredDataSourceInternal(pipeline, fb);
            if (nativeShaderDataSource.NativeHandle == IntPtr.Zero)
            {
                return default;
            }

            return new DeferredDataSource(nativeShaderDataSource);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativeShaderDataSource CreateTextureAssetSourceInternal(ushort samplerIndex, string uniformName, TextureAsset texture);

        public static TextureAssetSource CreateTextureAssetSource(ushort samplerIndex, string uniformName, TextureAsset texture)
        {
            NativeShaderDataSource nativeShaderDataSource = CreateTextureAssetSourceInternal(samplerIndex, uniformName, texture);
            if (nativeShaderDataSource.NativeHandle == IntPtr.Zero)
            {
                return default;
            }

            return new TextureAssetSource(nativeShaderDataSource);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static NativeShaderDataSource CreateBlinnPhongDataSourceInternal();

        public static BlinnPhongDataSource CreateBlinnPhongDataSource()
        {
            NativeShaderDataSource nativeShaderDataSource = CreateBlinnPhongDataSourceInternal();
            if (nativeShaderDataSource.NativeHandle == IntPtr.Zero)
            {
                return default;
            }

            return new BlinnPhongDataSource(nativeShaderDataSource);
        }
    }
#pragma warning restore CS0169
}
