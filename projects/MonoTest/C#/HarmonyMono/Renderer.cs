using System;
using System.Collections.Generic;
using System.Linq;
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

    public struct Texture
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

    public static class Renderer
    {
    }
}
