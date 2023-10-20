

using System.Runtime.CompilerServices;

namespace Harmony
{
    public static class VectorGraphics
    {

        public enum Layer : byte
        {
            One,
            Two,
            Three,
            Four,
            Five,
            Six,
            Seven,
            Eight
        }

        public struct NVGcolor
        {
            public float r, g, b, a;

            public NVGcolor(float _r, float _g, float _b, float _a)
            {
                r = _r;
                g = _g;
                b = _b; 
                a = _a;
            }
        };

        public struct NVGpaint
        {
            float xform1;
            float xform2;
            float xform3;
            float xform4;
            float xform5;
            float xform6;
            float extent_x;
            float extent_y;
            float radius;
            float feather;
            NVGcolor innerColor;
            NVGcolor outerColor;
            int image;
        };

        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       FontFace(Layer layer, string font);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       FontSize(Layer layer, float size);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       FontBlur(Layer layer, int blur);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Text(Layer layer, float x, float y, string str);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       TextLetterSpacing(Layer layer, float spacing);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       TextLineHeight(Layer layer, float line_height);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       TextAlign(Layer layer, int align);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       FontFaceId(Layer layer, int font);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       TextBox(Layer layer, float x, float y, float break_row_width, string str, string end);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       ShapeAntiAlias(Layer layer, int enabled);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       StrokeColor(Layer layer, NVGcolor color);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       StrokePaint(Layer layer, NVGpaint paint);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       FillColor(Layer layer, NVGcolor color);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       FillPaint(Layer layer, NVGpaint paint);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       MiterLimit(Layer layer, float limit);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       StrokeWidth(Layer layer, float size);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       LineCap(Layer layer, int cap);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       LineJoin(Layer layer, int join);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       GlobalAlpha(Layer layer, float alpha);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       ResetTransform(Layer layer);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Transform(Layer layer, float a, float b, float c, float d, float e, float f);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Translate(Layer layer, float x, float y);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Rotate(Layer layer, float angle);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       SkewX(Layer layer, float angle);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       SkewY(Layer layer, float angle);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Scale(Layer layer, float x, float y);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       CurrentTransform(Layer layer, out float xform);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       ImageSize(Layer layer, int image, out int w, out int h);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       DeleteImage(Layer layer, int image);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Scissor(Layer layer, float x, float y, float w, float h);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       IntersectScissor(Layer layer, float x, float y, float w, float h);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       ResetScissor(Layer layer);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       BeginPath(Layer layer);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       MoveTo(Layer layer, float x, float y);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       LineTo(Layer layer, float x, float y);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       BezierTo(Layer layer, float c1x, float c1y, float c2x, float c2y, float x, float y);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       QuadTo(Layer layer, float cx, float cy, float x, float y);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       ArcTo(Layer layer, float x1, float y1, float x2, float y2, float radius);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       ClosePath(Layer layer);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       PathWinding(Layer layer, int dir);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Arc(Layer layer, float cx, float cy, float r, float a0, float a1, int dir);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Rect(Layer layer, float x, float y, float w, float h);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       RoundedRect(Layer layer, float x, float y, float w, float h, float r);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       RoundedRectVarying(Layer layer, float x, float y, float w, float h, float rad_top_left, float rad_top_right, float rad_bottom_right, float rad_bottom_left);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Ellipse(Layer layer, float cx, float cy, float rx, float ry);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Circle(Layer layer, float cx, float cy, float r);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Fill(Layer layer);        
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void       Stroke(Layer layer);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NVGpaint   LinearGradient(Layer layer, float sx, float sy, float ex, float ey, NVGcolor icol, NVGcolor ocol);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NVGpaint   BoxGradient(Layer layer, float x, float y, float w, float h, float r, float f, NVGcolor icol, NVGcolor ocol);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NVGpaint   RadialGradient(Layer layer, float cx, float cy, float inr, float outr, NVGcolor icol, NVGcolor ocol);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NVGpaint   ImagePattern(Layer layer, float ox, float oy, float ex, float ey, float angle, int image, float alpha);
    }
}
