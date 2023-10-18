

namespace Harmony
{
    public static class VectorGraphics
    {

        public enum harmony_vg_layer : byte
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
            float r, g, b, a;
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

        public extern static void       font_face(harmony_vg_layer layer, string font);
        public extern static void       font_size(harmony_vg_layer layer, float size);
        public extern static void       font_blur(harmony_vg_layer layer, int blur);
        public extern static void       text(harmony_vg_layer layer, float x, float y, string str);
        public extern static void       text_letter_spacing(harmony_vg_layer layer, float spacing);
        public extern static void       text_line_height(harmony_vg_layer layer, float line_height);
        public extern static void       text_align(harmony_vg_layer layer, int align);
        public extern static void       font_face_id(harmony_vg_layer layer, int font);
        public extern static void       text_box(harmony_vg_layer layer, float x, float y, float break_row_width, string str, string end);
        public extern static void       shape_anti_alias(harmony_vg_layer layer, int enabled);
        public extern static void       stroke_color(harmony_vg_layer layer, NVGcolor color);
        public extern static void       stroke_paint(harmony_vg_layer layer, NVGpaint paint);
        public extern static void       fill_color(harmony_vg_layer layer, NVGcolor color);
        public extern static void       fill_paint(harmony_vg_layer layer, NVGpaint paint);
        public extern static void       miter_limit(harmony_vg_layer layer, float limit);
        public extern static void       stroke_width(harmony_vg_layer layer, float size);
        public extern static void       line_cap(harmony_vg_layer layer, int cap);
        public extern static void       line_join(harmony_vg_layer layer, int join);
        public extern static void       global_alpha(harmony_vg_layer layer, float alpha);
        public extern static void       reset_transform(harmony_vg_layer layer);
        public extern static void       transform(harmony_vg_layer layer, float a, float b, float c, float d, float e, float f);
        public extern static void       translate(harmony_vg_layer layer, float x, float y);
        public extern static void       rotate(harmony_vg_layer layer, float angle);
        public extern static void       skew_x(harmony_vg_layer layer, float angle);
        public extern static void       skew_y(harmony_vg_layer layer, float angle);
        public extern static void       scale(harmony_vg_layer layer, float x, float y);
        public extern static void       current_transform(harmony_vg_layer layer, out float xform);
        public extern static void       image_size(harmony_vg_layer layer, int image, out int w, out int h);
        public extern static void       delete_image(harmony_vg_layer layer, int image);
        public extern static void       scissor(harmony_vg_layer layer, float x, float y, float w, float h);
        public extern static void       intersect_scissor(harmony_vg_layer layer, float x, float y, float w, float h);
        public extern static void       reset_scissor(harmony_vg_layer layer);
        public extern static void       begin_path(harmony_vg_layer layer);
        public extern static void       move_to(harmony_vg_layer layer, float x, float y);
        public extern static void       line_to(harmony_vg_layer layer, float x, float y);
        public extern static void       bezier_to(harmony_vg_layer layer, float c1x, float c1y, float c2x, float c2y, float x, float y);
        public extern static void       quad_to(harmony_vg_layer layer, float cx, float cy, float x, float y);
        public extern static void       arc_to(harmony_vg_layer layer, float x1, float y1, float x2, float y2, float radius);
        public extern static void       close_path(harmony_vg_layer layer);
        public extern static void       path_winding(harmony_vg_layer layer, int dir);
        public extern static void       arc(harmony_vg_layer layer, float cx, float cy, float r, float a0, float a1, int dir);
        public extern static void       rect(harmony_vg_layer layer, float x, float y, float w, float h);
        public extern static void       rounded_rect(harmony_vg_layer layer, float x, float y, float w, float h, float r);
        public extern static void       rounded_rect_varying(harmony_vg_layer layer, float x, float y, float w, float h, float rad_top_left, float rad_top_right, float rad_bottom_right, float rad_bottom_left);
        public extern static void       ellipse(harmony_vg_layer layer, float cx, float cy, float rx, float ry);
        public extern static void       circle(harmony_vg_layer layer, float cx, float cy, float r);
        public extern static void       fill(harmony_vg_layer layer);
        public extern static void       stroke(harmony_vg_layer layer);
        public extern static NVGpaint   linear_gradient(harmony_vg_layer layer, float sx, float sy, float ex, float ey, NVGcolor icol, NVGcolor ocol);
        public extern static NVGpaint   box_gradient(harmony_vg_layer layer, float x, float y, float w, float h, float r, float f, NVGcolor icol, NVGcolor ocol);
        public extern static NVGpaint   radial_gradient(harmony_vg_layer layer, float cx, float cy, float inr, float outr, NVGcolor icol, NVGcolor ocol);
        public extern static NVGpaint   image_pattern(harmony_vg_layer layer, float ox, float oy, float ex, float ey, float angle, int image, float alpha);
    }
}
