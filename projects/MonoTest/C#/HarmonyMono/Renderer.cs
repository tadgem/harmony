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

    public struct ShaderDataSource
    {
        public IntPtr Handle;
    }

    public struct DeferredDataSource
    {
        public IntPtr Handle;
    }

    public struct TextureAssetSource
    {
        public IntPtr Handle;
    }

    public struct PipelineStage
    {
        public IntPtr Handle;
    }

    public struct PipelineDrawStage
    {
        public IntPtr handle;
    }

    public struct DrawScreenTextureStage
    {
        public IntPtr handle;
    }

    public struct PipelineStageRenderer
    {
        public IntPtr Handle;
    }

    public struct ScreenQuadRenderer
    {
        public IntPtr Handle;
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
        public extern static ShaderDataSource GetShaderDataSource(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static PipelineStage GetPipelineStage(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static PipelineStageRenderer GetPipelineStageRenderer(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Framebuffer PipelineAddFramebuffer(this Pipeline pipeline , string name, AttachmentType[] attachments, Resolution.Type resolutionType);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Framebuffer PipelineSetOutputFramebuffer(this Pipeline pipeline, Framebuffer fb);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void PipelineAddStage(this Pipeline pipeline, Framebuffer fb, PipelineStage stage);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void PipelineStageAddDataSource(this PipelineStage pipeline, ShaderDataSource source);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static PipelineDrawStage CreatePipelineDrawStage(string name, ShaderProgram shader, PipelineStageRenderer renderer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static ScreenQuadRenderer CreateScreenQuadRenderer(string name, ShaderProgram shader, PipelineStageRenderer renderer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static DeferredDataSource CreateDeferredDataSource(Framebuffer fb);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static ScreenQuadRenderer CreateTextureAssetSource(ushort samplerIndex, string uniformName, TextureAsset texture);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static ScreenQuadRenderer CreateDrawScreenTextureStage(ShaderProgram shader, AttachmentType attachmentType, Framebuffer[] framebuffers);
    }
}
