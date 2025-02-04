static const uint8_t vs_nanovg_fill_glsl[511] = {
        0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00,
        0xcf, 0xda, 0x1b, 0x94, 0x02, 0x00, 0x0a,
        0x75, // VSH............u
        0x5f, 0x76, 0x69, 0x65, 0x77, 0x53, 0x69, 0x7a,
        0x65, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00,
        0x00, // _viewSize.......
        0x00, 0x00, 0x00, 0x0b, 0x75, 0x5f, 0x68, 0x61,
        0x6c, 0x66, 0x54, 0x65, 0x78, 0x65, 0x6c,
        0x02, // ....u_halfTexel.
        0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xc1, 0x01, 0x00, 0x00, 0x61, 0x74,
        0x74, // .............att
        0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x76,
        0x65, 0x63, 0x32, 0x20, 0x61, 0x5f, 0x70,
        0x6f, // ribute vec2 a_po
        0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a,
        0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75,
        0x74, // sition;.attribut
        0x65, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x61,
        0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f,
        0x72, // e vec2 a_texcoor
        0x64, 0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79,
        0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63,
        0x32, // d0;.varying vec2
        0x20, 0x76, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74,
        0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x76, 0x61,
        0x72, //  v_position;.var
        0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63,
        0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78,
        0x63, // ying vec2 v_texc
        0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75,
        0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20,
        0x76, // oord0;.uniform v
        0x65, 0x63, 0x34, 0x20, 0x75, 0x5f, 0x76, 0x69,
        0x65, 0x77, 0x53, 0x69, 0x7a, 0x65, 0x3b,
        0x0a, // ec4 u_viewSize;.
        0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20,
        0x76, 0x65, 0x63, 0x34, 0x20, 0x75, 0x5f,
        0x68, // uniform vec4 u_h
        0x61, 0x6c, 0x66, 0x54, 0x65, 0x78, 0x65, 0x6c,
        0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20,
        0x6d, // alfTexel;.void m
        0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b,
        0x0a, 0x20, 0x20, 0x76, 0x5f, 0x70, 0x6f,
        0x73, // ain ().{.  v_pos
        0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20,
        0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74,
        0x69, // ition = a_positi
        0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x76, 0x5f,
        0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72,
        0x64, // on;.  v_texcoord
        0x30, 0x20, 0x3d, 0x20, 0x28, 0x61, 0x5f, 0x74,
        0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64,
        0x30, // 0 = (a_texcoord0
        0x20, 0x2b, 0x20, 0x75, 0x5f, 0x68, 0x61, 0x6c,
        0x66, 0x54, 0x65, 0x78, 0x65, 0x6c, 0x2e,
        0x78, //  + u_halfTexel.x
        0x79, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x76, 0x65,
        0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76,
        0x61, // y);.  vec4 tmpva
        0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74,
        0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31,
        0x2e, // r_1;.  tmpvar_1.
        0x7a, 0x77, 0x20, 0x3d, 0x20, 0x76, 0x65, 0x63,
        0x32, 0x28, 0x30, 0x2e, 0x30, 0x2c, 0x20,
        0x31, // zw = vec2(0.0, 1
        0x2e, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74,
        0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31,
        0x2e, // .0);.  tmpvar_1.
        0x78, 0x20, 0x3d, 0x20, 0x28, 0x28, 0x28, 0x32,
        0x2e, 0x30, 0x20, 0x2a, 0x20, 0x61, 0x5f,
        0x70, // x = (((2.0 * a_p
        0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e,
        0x78, 0x29, 0x20, 0x2f, 0x20, 0x75, 0x5f,
        0x76, // osition.x) / u_v
        0x69, 0x65, 0x77, 0x53, 0x69, 0x7a, 0x65, 0x2e,
        0x78, 0x29, 0x20, 0x2d, 0x20, 0x31, 0x2e,
        0x30, // iewSize.x) - 1.0
        0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70,
        0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x79,
        0x20, // );.  tmpvar_1.y
        0x3d, 0x20, 0x28, 0x31, 0x2e, 0x30, 0x20, 0x2d,
        0x20, 0x28, 0x28, 0x32, 0x2e, 0x30, 0x20,
        0x2a, // = (1.0 - ((2.0 *
        0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74,
        0x69, 0x6f, 0x6e, 0x2e, 0x79, 0x29, 0x20,
        0x2f, //  a_position.y) /
        0x20, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x53,
        0x69, 0x7a, 0x65, 0x2e, 0x79, 0x29, 0x29,
        0x3b, //  u_viewSize.y));
        0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x50, 0x6f,
        0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20,
        0x3d, // .  gl_Position =
        0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f,
        0x31, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a,
        0x00, //  tmpvar_1;.}...
};

static const uint8_t vs_nanovg_fill_essl[553] = {
        0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00,
        0xcf, 0xda, 0x1b, 0x94, 0x02, 0x00, 0x0a,
        0x75, // VSH............u
        0x5f, 0x76, 0x69, 0x65, 0x77, 0x53, 0x69, 0x7a,
        0x65, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00,
        0x00, // _viewSize.......
        0x00, 0x00, 0x00, 0x0b, 0x75, 0x5f, 0x68, 0x61,
        0x6c, 0x66, 0x54, 0x65, 0x78, 0x65, 0x6c,
        0x02, // ....u_halfTexel.
        0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xeb, 0x01, 0x00, 0x00, 0x61, 0x74,
        0x74, // .............att
        0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x68,
        0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65,
        0x63, // ribute highp vec
        0x32, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69,
        0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x61,
        0x74, // 2 a_position;.at
        0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20,
        0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76,
        0x65, // tribute highp ve
        0x63, 0x32, 0x20, 0x61, 0x5f, 0x74, 0x65, 0x78,
        0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b,
        0x0a, // c2 a_texcoord0;.
        0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20,
        0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76,
        0x65, // varying highp ve
        0x63, 0x32, 0x20, 0x76, 0x5f, 0x70, 0x6f, 0x73,
        0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a,
        0x76, // c2 v_position;.v
        0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68,
        0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65,
        0x63, // arying highp vec
        0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63,
        0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a,
        0x75, // 2 v_texcoord0;.u
        0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x68,
        0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65,
        0x63, // niform highp vec
        0x34, 0x20, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77,
        0x53, 0x69, 0x7a, 0x65, 0x3b, 0x0a, 0x75,
        0x6e, // 4 u_viewSize;.un
        0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x68, 0x69,
        0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63,
        0x34, // iform highp vec4
        0x20, 0x75, 0x5f, 0x68, 0x61, 0x6c, 0x66, 0x54,
        0x65, 0x78, 0x65, 0x6c, 0x3b, 0x0a, 0x76,
        0x6f, //  u_halfTexel;.vo
        0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20,
        0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20,
        0x76, // id main ().{.  v
        0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f,
        0x6e, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x70,
        0x6f, // _position = a_po
        0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a,
        0x20, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78,
        0x63, // sition;.  v_texc
        0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x3d, 0x20,
        0x28, 0x61, 0x5f, 0x74, 0x65, 0x78, 0x63,
        0x6f, // oord0 = (a_texco
        0x6f, 0x72, 0x64, 0x30, 0x20, 0x2b, 0x20, 0x75,
        0x5f, 0x68, 0x61, 0x6c, 0x66, 0x54, 0x65,
        0x78, // ord0 + u_halfTex
        0x65, 0x6c, 0x2e, 0x78, 0x79, 0x29, 0x3b, 0x0a,
        0x20, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70,
        0x20, // el.xy);.  highp
        0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70,
        0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a,
        0x20, // vec4 tmpvar_1;.
        0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f,
        0x31, 0x2e, 0x7a, 0x77, 0x20, 0x3d, 0x20,
        0x76, //  tmpvar_1.zw = v
        0x65, 0x63, 0x32, 0x28, 0x30, 0x2e, 0x30, 0x2c,
        0x20, 0x31, 0x2e, 0x30, 0x29, 0x3b, 0x0a,
        0x20, // ec2(0.0, 1.0);.
        0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f,
        0x31, 0x2e, 0x78, 0x20, 0x3d, 0x20, 0x28,
        0x28, //  tmpvar_1.x = ((
        0x28, 0x32, 0x2e, 0x30, 0x20, 0x2a, 0x20, 0x61,
        0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69,
        0x6f, // (2.0 * a_positio
        0x6e, 0x2e, 0x78, 0x29, 0x20, 0x2f, 0x20, 0x75,
        0x5f, 0x76, 0x69, 0x65, 0x77, 0x53, 0x69,
        0x7a, // n.x) / u_viewSiz
        0x65, 0x2e, 0x78, 0x29, 0x20, 0x2d, 0x20, 0x31,
        0x2e, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20,
        0x74, // e.x) - 1.0);.  t
        0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e,
        0x79, 0x20, 0x3d, 0x20, 0x28, 0x31, 0x2e,
        0x30, // mpvar_1.y = (1.0
        0x20, 0x2d, 0x20, 0x28, 0x28, 0x32, 0x2e, 0x30,
        0x20, 0x2a, 0x20, 0x61, 0x5f, 0x70, 0x6f,
        0x73, //  - ((2.0 * a_pos
        0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x79, 0x29,
        0x20, 0x2f, 0x20, 0x75, 0x5f, 0x76, 0x69,
        0x65, // ition.y) / u_vie
        0x77, 0x53, 0x69, 0x7a, 0x65, 0x2e, 0x79, 0x29,
        0x29, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c,
        0x5f, // wSize.y));.  gl_
        0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e,
        0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76,
        0x61, // Position = tmpva
        0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a,
        0x00, // r_1;.}...
};

static const uint8_t vs_nanovg_fill_spv[1481] = {
        0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00,
        0xcf, 0xda, 0x1b, 0x94, 0x02, 0x00, 0x0b,
        0x75, // VSH............u
        0x5f, 0x68, 0x61, 0x6c, 0x66, 0x54, 0x65, 0x78,
        0x65, 0x6c, 0x02, 0x00, 0x10, 0x00, 0x01,
        0x00, // _halfTexel......
        0x00, 0x00, 0x00, 0x00, 0x0a, 0x75, 0x5f, 0x76,
        0x69, 0x65, 0x77, 0x53, 0x69, 0x7a, 0x65,
        0x02, // .....u_viewSize.
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x84, 0x05, 0x00, 0x00, 0x03, 0x02,
        0x23, // ...............#
        0x07, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x00, 0x08,
        0x00, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, // ................
        0x00, 0x11, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00,
        0x00, // ................
        0x00, 0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73, 0x74,
        0x64, 0x2e, 0x34, 0x35, 0x30, 0x00, 0x00,
        0x00, // .GLSL.std.450...
        0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00,
        0x0a, // ................
        0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
        0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00,
        0x00, // .........main...
        0x00, 0x43, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00,
        0x00, 0x4f, 0x00, 0x00, 0x00, 0x53, 0x00,
        0x00, // .C...F...O...S..
        0x00, 0x56, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03,
        0x00, 0x05, 0x00, 0x00, 0x00, 0xf4, 0x01,
        0x00, // .V..............
        0x00, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00,
        0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00,
        0x00, // .........main...
        0x00, 0x05, 0x00, 0x06, 0x00, 0x1c, 0x00, 0x00,
        0x00, 0x55, 0x6e, 0x69, 0x66, 0x6f, 0x72,
        0x6d, // .........Uniform
        0x42, 0x6c, 0x6f, 0x63, 0x6b, 0x00, 0x00, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x1c, 0x00,
        0x00, // Block...........
        0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x76,
        0x69, 0x65, 0x77, 0x53, 0x69, 0x7a, 0x65,
        0x00, // .....u_viewSize.
        0x00, 0x06, 0x00, 0x06, 0x00, 0x1c, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x00, 0x00, 0x75, 0x5f,
        0x68, // .............u_h
        0x61, 0x6c, 0x66, 0x54, 0x65, 0x78, 0x65, 0x6c,
        0x00, 0x05, 0x00, 0x03, 0x00, 0x1e, 0x00,
        0x00, // alfTexel........
        0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05,
        0x00, 0x43, 0x00, 0x00, 0x00, 0x61, 0x5f,
        0x70, // .........C...a_p
        0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00,
        0x00, 0x05, 0x00, 0x05, 0x00, 0x46, 0x00,
        0x00, // osition......F..
        0x00, 0x61, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f,
        0x6f, 0x72, 0x64, 0x30, 0x00, 0x05, 0x00,
        0x0a, // .a_texcoord0....
        0x00, 0x4f, 0x00, 0x00, 0x00, 0x40, 0x65, 0x6e,
        0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e,
        0x74, // .O...@entryPoint
        0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x2e, 0x67,
        0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74,
        0x69, // Output.gl_Positi
        0x6f, 0x6e, 0x00, 0x00, 0x00, 0x05, 0x00, 0x0a,
        0x00, 0x53, 0x00, 0x00, 0x00, 0x40, 0x65,
        0x6e, // on.......S...@en
        0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74,
        0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x2e,
        0x76, // tryPointOutput.v
        0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f,
        0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,
        0x0a, // _position.......
        0x00, 0x56, 0x00, 0x00, 0x00, 0x40, 0x65, 0x6e,
        0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e,
        0x74, // .V...@entryPoint
        0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x2e, 0x76,
        0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f,
        0x72, // Output.v_texcoor
        0x64, 0x30, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05,
        0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, // d0...H..........
        0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x48, 0x00, 0x05, 0x00, 0x1c, 0x00,
        0x00, // .#.......H......
        0x00, 0x01, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00,
        0x00, 0x10, 0x00, 0x00, 0x00, 0x47, 0x00,
        0x03, // .....#.......G..
        0x00, 0x1c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
        0x00, 0x47, 0x00, 0x04, 0x00, 0x1e, 0x00,
        0x00, // .........G......
        0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x47, 0x00, 0x04, 0x00, 0x1e, 0x00,
        0x00, // .".......G......
        0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x47, 0x00, 0x04, 0x00, 0x43, 0x00,
        0x00, // .!.......G...C..
        0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x47, 0x00, 0x04, 0x00, 0x46, 0x00,
        0x00, // .........G...F..
        0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x47, 0x00, 0x04, 0x00, 0x4f, 0x00,
        0x00, // .........G...O..
        0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x47, 0x00, 0x04, 0x00, 0x53, 0x00,
        0x00, // .........G...S..
        0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x47, 0x00, 0x04, 0x00, 0x56, 0x00,
        0x00, // .........G...V..
        0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x13, 0x00, 0x02, 0x00, 0x02, 0x00,
        0x00, // ................
        0x00, 0x21, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x02, 0x00, 0x00, 0x00, 0x16, 0x00,
        0x03, // .!..............
        0x00, 0x06, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
        0x00, 0x17, 0x00, 0x04, 0x00, 0x07, 0x00,
        0x00, // ..... ..........
        0x00, 0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
        0x00, 0x17, 0x00, 0x04, 0x00, 0x09, 0x00,
        0x00, // ................
        0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
        0x00, 0x15, 0x00, 0x04, 0x00, 0x12, 0x00,
        0x00, // ................
        0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x2b, 0x00, 0x04, 0x00, 0x12, 0x00,
        0x00, // . .......+......
        0x00, 0x13, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x2b, 0x00, 0x04, 0x00, 0x06, 0x00,
        0x00, // .........+......
        0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x1e, 0x00, 0x04, 0x00, 0x1c, 0x00,
        0x00, // ................
        0x00, 0x09, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00,
        0x00, 0x20, 0x00, 0x04, 0x00, 0x1d, 0x00,
        0x00, // ......... ......
        0x00, 0x02, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
        0x00, 0x3b, 0x00, 0x04, 0x00, 0x1d, 0x00,
        0x00, // .........;......
        0x00, 0x1e, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
        0x00, 0x20, 0x00, 0x04, 0x00, 0x1f, 0x00,
        0x00, // ......... ......
        0x00, 0x02, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00,
        0x00, 0x2b, 0x00, 0x04, 0x00, 0x12, 0x00,
        0x00, // .........+......
        0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x2b, 0x00, 0x04, 0x00, 0x06, 0x00,
        0x00, // .%.......+......
        0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x40, 0x15, 0x00, 0x04, 0x00, 0x27, 0x00,
        0x00, // .&......@....'..
        0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x2b, 0x00, 0x04, 0x00, 0x27, 0x00,
        0x00, // . .......+...'..
        0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x20, 0x00, 0x04, 0x00, 0x2d, 0x00,
        0x00, // .(....... ...-..
        0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
        0x00, 0x2b, 0x00, 0x04, 0x00, 0x06, 0x00,
        0x00, // .........+......
        0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
        0x3f, 0x2b, 0x00, 0x04, 0x00, 0x27, 0x00,
        0x00, // .1......?+...'..
        0x00, 0x33, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x20, 0x00, 0x04, 0x00, 0x42, 0x00,
        0x00, // .3....... ...B..
        0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
        0x00, 0x3b, 0x00, 0x04, 0x00, 0x42, 0x00,
        0x00, // .........;...B..
        0x00, 0x43, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x3b, 0x00, 0x04, 0x00, 0x42, 0x00,
        0x00, // .C.......;...B..
        0x00, 0x46, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x20, 0x00, 0x04, 0x00, 0x4e, 0x00,
        0x00, // .F....... ...N..
        0x00, 0x03, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00,
        0x00, 0x3b, 0x00, 0x04, 0x00, 0x4e, 0x00,
        0x00, // .........;...N..
        0x00, 0x4f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x20, 0x00, 0x04, 0x00, 0x52, 0x00,
        0x00, // .O....... ...R..
        0x00, 0x03, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
        0x00, 0x3b, 0x00, 0x04, 0x00, 0x52, 0x00,
        0x00, // .........;...R..
        0x00, 0x53, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x3b, 0x00, 0x04, 0x00, 0x52, 0x00,
        0x00, // .S.......;...R..
        0x00, 0x56, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x36, 0x00, 0x05, 0x00, 0x02, 0x00,
        0x00, // .V.......6......
        0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x00,
        0x02, // ................
        0x00, 0x05, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04,
        0x00, 0x07, 0x00, 0x00, 0x00, 0x44, 0x00,
        0x00, // .....=.......D..
        0x00, 0x43, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04,
        0x00, 0x07, 0x00, 0x00, 0x00, 0x47, 0x00,
        0x00, // .C...=.......G..
        0x00, 0x46, 0x00, 0x00, 0x00, 0x41, 0x00, 0x05,
        0x00, 0x1f, 0x00, 0x00, 0x00, 0x73, 0x00,
        0x00, // .F...A.......s..
        0x00, 0x1e, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00,
        0x00, 0x3d, 0x00, 0x04, 0x00, 0x09, 0x00,
        0x00, // .........=......
        0x00, 0x74, 0x00, 0x00, 0x00, 0x73, 0x00, 0x00,
        0x00, 0x4f, 0x00, 0x07, 0x00, 0x07, 0x00,
        0x00, // .t...s...O......
        0x00, 0x75, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00,
        0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, // .u...t...t......
        0x00, 0x01, 0x00, 0x00, 0x00, 0x81, 0x00, 0x05,
        0x00, 0x07, 0x00, 0x00, 0x00, 0x76, 0x00,
        0x00, // .............v..
        0x00, 0x47, 0x00, 0x00, 0x00, 0x75, 0x00, 0x00,
        0x00, 0x51, 0x00, 0x05, 0x00, 0x06, 0x00,
        0x00, // .G...u...Q......
        0x00, 0x79, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x00,
        0x05, // .y...D..........
        0x00, 0x06, 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00,
        0x00, 0x26, 0x00, 0x00, 0x00, 0x79, 0x00,
        0x00, // .....z...&...y..
        0x00, 0x41, 0x00, 0x06, 0x00, 0x2d, 0x00, 0x00,
        0x00, 0x7b, 0x00, 0x00, 0x00, 0x1e, 0x00,
        0x00, // .A...-...{......
        0x00, 0x25, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00,
        0x00, 0x3d, 0x00, 0x04, 0x00, 0x06, 0x00,
        0x00, // .%...(...=......
        0x00, 0x7c, 0x00, 0x00, 0x00, 0x7b, 0x00, 0x00,
        0x00, 0x88, 0x00, 0x05, 0x00, 0x06, 0x00,
        0x00, // .|...{..........
        0x00, 0x7d, 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00,
        0x00, 0x7c, 0x00, 0x00, 0x00, 0x83, 0x00,
        0x05, // .}...z...|......
        0x00, 0x06, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00,
        0x00, 0x7d, 0x00, 0x00, 0x00, 0x31, 0x00,
        0x00, // .....~...}...1..
        0x00, 0x51, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00,
        0x00, 0x80, 0x00, 0x00, 0x00, 0x44, 0x00,
        0x00, // .Q...........D..
        0x00, 0x01, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05,
        0x00, 0x06, 0x00, 0x00, 0x00, 0x81, 0x00,
        0x00, // ................
        0x00, 0x26, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x00, 0x41, 0x00, 0x06, 0x00, 0x2d, 0x00,
        0x00, // .&.......A...-..
        0x00, 0x82, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00,
        0x00, 0x25, 0x00, 0x00, 0x00, 0x33, 0x00,
        0x00, // .........%...3..
        0x00, 0x3d, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00,
        0x00, 0x83, 0x00, 0x00, 0x00, 0x82, 0x00,
        0x00, // .=..............
        0x00, 0x88, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00,
        0x00, 0x84, 0x00, 0x00, 0x00, 0x81, 0x00,
        0x00, // ................
        0x00, 0x83, 0x00, 0x00, 0x00, 0x83, 0x00, 0x05,
        0x00, 0x06, 0x00, 0x00, 0x00, 0x85, 0x00,
        0x00, // ................
        0x00, 0x31, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00,
        0x00, 0x50, 0x00, 0x07, 0x00, 0x09, 0x00,
        0x00, // .1.......P......
        0x00, 0x86, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00,
        0x00, 0x85, 0x00, 0x00, 0x00, 0x14, 0x00,
        0x00, // .....~..........
        0x00, 0x31, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03,
        0x00, 0x4f, 0x00, 0x00, 0x00, 0x86, 0x00,
        0x00, // .1...>...O......
        0x00, 0x3e, 0x00, 0x03, 0x00, 0x53, 0x00, 0x00,
        0x00, 0x44, 0x00, 0x00, 0x00, 0x3e, 0x00,
        0x03, // .>...S...D...>..
        0x00, 0x56, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00,
        0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00,
        0x01, // .V...v.......8..
        0x00, 0x00, 0x02, 0x01, 0x00, 0x10, 0x00, 0x20,
        0x00, // ....... .
};

static const uint8_t vs_nanovg_fill_dx9[438] = {
        0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00,
        0xcf, 0xda, 0x1b, 0x94, 0x02, 0x00, 0x0b,
        0x75, // VSH............u
        0x5f, 0x68, 0x61, 0x6c, 0x66, 0x54, 0x65, 0x78,
        0x65, 0x6c, 0x02, 0x01, 0x01, 0x00, 0x01,
        0x00, // _halfTexel......
        0x00, 0x00, 0x00, 0x00, 0x0a, 0x75, 0x5f, 0x76,
        0x69, 0x65, 0x77, 0x53, 0x69, 0x7a, 0x65,
        0x02, // .....u_viewSize.
        0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x78, 0x01, 0x00, 0x00, 0x00, 0x03,
        0xfe, // .........x......
        0xff, 0xfe, 0xff, 0x28, 0x00, 0x43, 0x54, 0x41,
        0x42, 0x1c, 0x00, 0x00, 0x00, 0x72, 0x00,
        0x00, // ...(.CTAB....r..
        0x00, 0x00, 0x03, 0xfe, 0xff, 0x02, 0x00, 0x00,
        0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x91,
        0x00, // ................
        0x00, 0x6b, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00,
        0x00, 0x02, 0x00, 0x01, 0x00, 0x01, 0x00,
        0x00, // .k...D..........
        0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x60, 0x00, 0x00, 0x00, 0x02, 0x00,
        0x00, // .P.......`......
        0x00, 0x01, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f,
        0x68, // .....P.......u_h
        0x61, 0x6c, 0x66, 0x54, 0x65, 0x78, 0x65, 0x6c,
        0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00,
        0x04, // alfTexel........
        0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77,
        0x53, // .........u_viewS
        0x69, 0x7a, 0x65, 0x00, 0x76, 0x73, 0x5f, 0x33,
        0x5f, 0x30, 0x00, 0x4d, 0x69, 0x63, 0x72,
        0x6f, // ize.vs_3_0.Micro
        0x73, 0x6f, 0x66, 0x74, 0x20, 0x28, 0x52, 0x29,
        0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53,
        0x68, // soft (R) HLSL Sh
        0x61, 0x64, 0x65, 0x72, 0x20, 0x43, 0x6f, 0x6d,
        0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x31,
        0x30, // ader Compiler 10
        0x2e, 0x31, 0x00, 0xab, 0xab, 0x51, 0x00, 0x00,
        0x05, 0x02, 0x00, 0x0f, 0xa0, 0x00, 0x00,
        0x80, // .1...Q..........
        0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00,
        0x00, // ....?...........
        0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x0f,
        0x90, 0x1f, 0x00, 0x00, 0x02, 0x05, 0x00,
        0x00, // ................
        0x80, 0x01, 0x00, 0x0f, 0x90, 0x1f, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x0f, // ................
        0xe0, 0x1f, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00,
        0x80, 0x01, 0x00, 0x03, 0xe0, 0x1f, 0x00,
        0x00, // ................
        0x02, 0x05, 0x00, 0x01, 0x80, 0x02, 0x00, 0x03,
        0xe0, 0x02, 0x00, 0x00, 0x03, 0x02, 0x00,
        0x03, // ................
        0xe0, 0x01, 0x00, 0xe4, 0xa0, 0x01, 0x00, 0xe4,
        0x90, 0x06, 0x00, 0x00, 0x02, 0x00, 0x00,
        0x01, // ................
        0x80, 0x00, 0x00, 0x00, 0xa0, 0x02, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00,
        0xd0, // ................
        0x90, 0x00, 0x00, 0xd0, 0x90, 0x04, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00,
        0x55, // ...............U
        0x80, 0x00, 0x00, 0x00, 0x80, 0x02, 0x00, 0x00,
        0xa0, 0x06, 0x00, 0x00, 0x02, 0x00, 0x00,
        0x01, // ................
        0x80, 0x00, 0x00, 0x55, 0xa0, 0x04, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x02, 0xe0, 0x00, 0x00,
        0xaa, // ...U............
        0x80, 0x00, 0x00, 0x00, 0x81, 0x02, 0x00, 0x55,
        0xa0, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00,
        0x0c, // .......U........
        0xe0, 0x02, 0x00, 0x64, 0xa0, 0x01, 0x00, 0x00,
        0x02, 0x01, 0x00, 0x03, 0xe0, 0x00, 0x00,
        0xe4, // ...d............
        0x90, 0xff, 0xff, 0x00, 0x00,
        0x00, // ......
};

static const uint8_t vs_nanovg_fill_dx11[587] = {
        0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00, 0xcf, 0xda,
        0x1b, 0x94, 0x01, 0x00, 0x0a,
        0x75, // VSH............u
        0x5f, 0x76, 0x69, 0x65, 0x77, 0x53, 0x69, 0x7a, 0x65, 0x02,
        0x00, 0x00, 0x00, 0x01, 0x00,
        0x00, // _viewSize.......
        0x00, 0x00, 0x00, 0x1c, 0x02, 0x00, 0x00, 0x44, 0x58, 0x42,
        0x43, 0x99, 0x64, 0x1c, 0x9f,
        0xec, // .......DXBC.d...
        0x38, 0xd9, 0xd2, 0x91, 0x86, 0xde, 0x66, 0x7d, 0x52, 0x06,
        0xfe, 0x01, 0x00, 0x00, 0x00,
        0x1c, // 8.....f}R.......
        0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00,
        0x00, 0x80, 0x00, 0x00, 0x00,
        0xf0, // .......,........
        0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x4c, 0x00, 0x00,
        0x00, 0x02, 0x00, 0x00, 0x00,
        0x08, // ...ISGNL........
        0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, // ...8............
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00,
        0x00, 0x41, 0x00, 0x00, 0x00,
        0x00, // ...........A....
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x00, 0x00,
        0x03, // ................
        0x03, 0x00, 0x00, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f,
        0x4e, 0x00, 0x54, 0x45, 0x58,
        0x43, // ...POSITION.TEXC
        0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0xab, 0x4f, 0x53, 0x47,
        0x4e, 0x68, 0x00, 0x00, 0x00,
        0x03, // OORD...OSGNh....
        0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, // .......P........
        0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x0f, 0x00, 0x00, 0x00,
        0x5c, // ................
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x03, 0x00, 0x00, 0x00,
        0x01, // ................
        0x00, 0x00, 0x00, 0x03, 0x0c, 0x00, 0x00, 0x5c, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, // ................
        0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x0c, 0x03, 0x00, 0x00,
        0x53, // ...............S
        0x56, 0x5f, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e,
        0x00, 0x54, 0x45, 0x58, 0x43,
        0x4f, // V_POSITION.TEXCO
        0x4f, 0x52, 0x44, 0x00, 0xab, 0xab, 0xab, 0x53, 0x48, 0x44,
        0x52, 0x24, 0x01, 0x00, 0x00,
        0x40, // ORD....SHDR$...@
        0x00, 0x01, 0x00, 0x49, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00,
        0x04, 0x46, 0x8e, 0x20, 0x00,
        0x00, // ...I...Y...F. ..
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00,
        0x03, 0x32, 0x10, 0x10, 0x00,
        0x00, // ......._...2....
        0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x03, 0x32, 0x10, 0x10,
        0x00, 0x01, 0x00, 0x00, 0x00,
        0x67, // ..._...2.......g
        0x00, 0x00, 0x04, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x00, 0x00,
        0x65, // .... ..........e
        0x00, 0x00, 0x03, 0x32, 0x20, 0x10, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x65, 0x00, 0x00, 0x03,
        0xc2, // ...2 ......e....
        0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00,
        0x02, 0x01, 0x00, 0x00, 0x00,
        0x00, //  ......h........
        0x00, 0x00, 0x07, 0x32, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x46, 0x10, 0x10, 0x00,
        0x00, // ...2.......F....
        0x00, 0x00, 0x00, 0x46, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x0e, 0x00, 0x00, 0x08,
        0x32, // ...F...........2
        0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x00, 0x10,
        0x00, 0x00, 0x00, 0x00, 0x00,
        0x46, // .......F.......F
        0x80, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x07,
        0x12, // . ..............
        0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x10,
        0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, //  ...............
        0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00,
        0x08, 0x22, 0x20, 0x10, 0x00,
        0x00, // @.........." ...
        0x00, 0x00, 0x00, 0x1a, 0x00, 0x10, 0x80, 0x41, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, // .......A........
        0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x36, 0x00, 0x00,
        0x08, 0xc2, 0x20, 0x10, 0x00,
        0x00, // @.....?6.... ...
        0x00, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, // ....@...........
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x36, 0x00, 0x00,
        0x05, 0x32, 0x20, 0x10, 0x00,
        0x01, // ......?6...2 ...
        0x00, 0x00, 0x00, 0x46, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x36, 0x00, 0x00, 0x05,
        0xc2, // ...F.......6....
        0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x06, 0x14, 0x10,
        0x00, 0x01, 0x00, 0x00, 0x00,
        0x3e, //  ..............>
        0x00, 0x00, 0x01, 0x00, 0x02, 0x01, 0x00, 0x10, 0x00, 0x10,
        0x00, // ...........
};

static const uint8_t vs_nanovg_fill_mtl[941] = {
        0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00, 0xcf, 0xda, 0x1b, 0x94,
        0x02, 0x00, 0x0b,
        0x75, // VSH............u
        0x5f, 0x68, 0x61, 0x6c, 0x66, 0x54, 0x65, 0x78, 0x65, 0x6c, 0x02, 0x01,
        0x10, 0x00, 0x01,
        0x00, // _halfTexel......
        0x00, 0x00, 0x00, 0x00, 0x0a, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x53,
        0x69, 0x7a, 0x65,
        0x02, // .....u_viewSize.
        0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x03, 0x00,
        0x00, 0x23, 0x69,
        0x6e, // .........h...#in
        0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61, 0x6c,
        0x5f, 0x73, 0x74,
        0x64, // clude <metal_std
        0x6c, 0x69, 0x62, 0x3e, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64,
        0x65, 0x20, 0x3c,
        0x73, // lib>.#include <s
        0x69, 0x6d, 0x64, 0x2f, 0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e, 0x0a,
        0x0a, 0x75, 0x73,
        0x69, // imd/simd.h>..usi
        0x6e, 0x67, 0x20, 0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63, 0x65,
        0x20, 0x6d, 0x65,
        0x74, // ng namespace met
        0x61, 0x6c, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20,
        0x5f, 0x47, 0x6c,
        0x6f, // al;..struct _Glo
        0x62, 0x61, 0x6c, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c,
        0x6f, 0x61, 0x74,
        0x34, // bal.{.    float4
        0x20, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x53, 0x69, 0x7a, 0x65, 0x3b,
        0x0a, 0x20, 0x20,
        0x20, //  u_viewSize;.
        0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x75, 0x5f, 0x68, 0x61,
        0x6c, 0x66, 0x54,
        0x65, //  float4 u_halfTe
        0x78, 0x65, 0x6c, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72,
        0x75, 0x63, 0x74,
        0x20, // xel;.};..struct
        0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f,
        0x6f, 0x75, 0x74,
        0x0a, // xlatMtlMain_out.
        0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32,
        0x20, 0x5f, 0x65,
        0x6e, // {.    float2 _en
        0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70,
        0x75, 0x74, 0x5f,
        0x76, // tryPointOutput_v
        0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x5b, 0x5b,
        0x75, 0x73, 0x65,
        0x72, // _position [[user
        0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x20,
        0x20, 0x20, 0x20,
        0x66, // (locn0)]];.    f
        0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, 0x5f, 0x65, 0x6e, 0x74, 0x72, 0x79,
        0x50, 0x6f, 0x69,
        0x6e, // loat2 _entryPoin
        0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, 0x76, 0x5f, 0x74, 0x65,
        0x78, 0x63, 0x6f,
        0x6f, // tOutput_v_texcoo
        0x72, 0x64, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c,
        0x6f, 0x63, 0x6e,
        0x31, // rd0 [[user(locn1
        0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f,
        0x61, 0x74, 0x34,
        0x20, // )]];.    float4
        0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20,
        0x5b, 0x5b, 0x70,
        0x6f, // gl_Position [[po
        0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b,
        0x0a, 0x0a, 0x73,
        0x74, // sition]];.};..st
        0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c,
        0x4d, 0x61, 0x69,
        0x6e, // ruct xlatMtlMain
        0x5f, 0x69, 0x6e, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c,
        0x6f, 0x61, 0x74,
        0x32, // _in.{.    float2
        0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20,
        0x5b, 0x5b, 0x61,
        0x74, //  a_position [[at
        0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x28, 0x30, 0x29, 0x5d, 0x5d,
        0x3b, 0x0a, 0x20,
        0x20, // tribute(0)]];.
        0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, 0x61, 0x5f, 0x74,
        0x65, 0x78, 0x63,
        0x6f, //   float2 a_texco
        0x6f, 0x72, 0x64, 0x30, 0x20, 0x5b, 0x5b, 0x61, 0x74, 0x74, 0x72, 0x69,
        0x62, 0x75, 0x74,
        0x65, // ord0 [[attribute
        0x28, 0x31, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x76,
        0x65, 0x72, 0x74,
        0x65, // (1)]];.};..verte
        0x78, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69,
        0x6e, 0x5f, 0x6f,
        0x75, // x xlatMtlMain_ou
        0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69,
        0x6e, 0x28, 0x78,
        0x6c, // t xlatMtlMain(xl
        0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e,
        0x20, 0x69, 0x6e,
        0x20, // atMtlMain_in in
        0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, 0x69, 0x6e, 0x5d, 0x5d,
        0x2c, 0x20, 0x63,
        0x6f, // [[stage_in]], co
        0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x20, 0x5f, 0x47, 0x6c, 0x6f, 0x62,
        0x61, 0x6c, 0x26,
        0x20, // nstant _Global&
        0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x75, 0x20, 0x5b, 0x5b, 0x62, 0x75, 0x66,
        0x66, 0x65, 0x72,
        0x28, // _mtl_u [[buffer(
        0x30, 0x29, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20,
        0x78, 0x6c, 0x61,
        0x74, // 0)]]).{.    xlat
        0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20,
        0x6f, 0x75, 0x74,
        0x20, // MtlMain_out out
        0x3d, 0x20, 0x7b, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75,
        0x74, 0x2e, 0x67,
        0x6c, // = {};.    out.gl
        0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20,
        0x66, 0x6c, 0x6f,
        0x61, // _Position = floa
        0x74, 0x34, 0x28, 0x28, 0x28, 0x32, 0x2e, 0x30, 0x20, 0x2a, 0x20, 0x69,
        0x6e, 0x2e, 0x61,
        0x5f, // t4(((2.0 * in.a_
        0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x29, 0x20,
        0x2f, 0x20, 0x5f,
        0x6d, // position.x) / _m
        0x74, 0x6c, 0x5f, 0x75, 0x2e, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x53,
        0x69, 0x7a, 0x65,
        0x2e, // tl_u.u_viewSize.
        0x78, 0x29, 0x20, 0x2d, 0x20, 0x31, 0x2e, 0x30, 0x2c, 0x20, 0x31, 0x2e,
        0x30, 0x20, 0x2d,
        0x20, // x) - 1.0, 1.0 -
        0x28, 0x28, 0x32, 0x2e, 0x30, 0x20, 0x2a, 0x20, 0x69, 0x6e, 0x2e, 0x61,
        0x5f, 0x70, 0x6f,
        0x73, // ((2.0 * in.a_pos
        0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x79, 0x29, 0x20, 0x2f, 0x20, 0x5f,
        0x6d, 0x74, 0x6c,
        0x5f, // ition.y) / _mtl_
        0x75, 0x2e, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x53, 0x69, 0x7a, 0x65,
        0x2e, 0x79, 0x29,
        0x2c, // u.u_viewSize.y),
        0x20, 0x30, 0x2e, 0x30, 0x2c, 0x20, 0x31, 0x2e, 0x30, 0x29, 0x3b, 0x0a,
        0x20, 0x20, 0x20,
        0x20, //  0.0, 1.0);.
        0x6f, 0x75, 0x74, 0x2e, 0x5f, 0x65, 0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f,
        0x69, 0x6e, 0x74,
        0x4f, // out._entryPointO
        0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, 0x76, 0x5f, 0x70, 0x6f, 0x73, 0x69,
        0x74, 0x69, 0x6f,
        0x6e, // utput_v_position
        0x20, 0x3d, 0x20, 0x69, 0x6e, 0x2e, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69,
        0x74, 0x69, 0x6f,
        0x6e, //  = in.a_position
        0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x5f, 0x65,
        0x6e, 0x74, 0x72,
        0x79, // ;.    out._entry
        0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f,
        0x76, 0x5f, 0x74,
        0x65, // PointOutput_v_te
        0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x3d, 0x20, 0x69, 0x6e,
        0x2e, 0x61, 0x5f,
        0x74, // xcoord0 = in.a_t
        0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x2b, 0x20, 0x5f,
        0x6d, 0x74, 0x6c,
        0x5f, // excoord0 + _mtl_
        0x75, 0x2e, 0x75, 0x5f, 0x68, 0x61, 0x6c, 0x66, 0x54, 0x65, 0x78, 0x65,
        0x6c, 0x2e, 0x78,
        0x79, // u.u_halfTexel.xy
        0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e,
        0x20, 0x6f, 0x75,
        0x74, // ;.    return out
        0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00, 0x02, 0x01, 0x00, 0x10, 0x00, 0x20,
        0x00, // ;.}........ .
};

extern const uint8_t *vs_nanovg_fill_pssl;

extern const uint32_t vs_nanovg_fill_pssl_size;
