#pragma once

#include "Rendering/Debug/debugdraw/debugdraw.h"
#include "Rendering/View.h"
#include "STL/HashMap.h"
#include "STL/Json.hpp"

namespace harmony {
    class GfxDebug {
    protected:
        inline static GfxDebug *p_Instance = nullptr;

        GfxDebug();

    public:
        enum Channel : char {
            Editor,
            Game
        };

        NLOHMANN_JSON_SERIALIZE_ENUM(Channel, {
            { Editor, "editor" },
            { Game, "game" },
        })

        ~GfxDebug();

        static GfxDebug *Get();

        DebugDrawEncoder *AddViewChannel(Channel channel);

        void RemoveViewChannel(Channel channel, DebugDrawEncoder *renderer);

        // void begin(Channel channel,uint16_t _viewId, bool _depthTestLess = true,
        // bgfx::Encoder* _encoder = NULL); void end(Channel channel);
        void push(Channel channel);

        void pop(Channel channel);

        void setDepthTestLess(Channel channel, bool _depthTestLess);

        void setState(Channel channel, bool _depthTest, bool _depthWrite,
                      bool _clockwise);

        void setColor(Channel channel, uint32_t _abgr);

        void setLod(Channel channel, uint8_t _lod);

        void setWireframe(Channel channel, bool _wireframe);

        void setStipple(Channel channel, bool _stipple, float _scale = 1.0f,
                        float _offset = 0.0f);

        void setSpin(Channel channel, float _spin);

        void setTransform(Channel channel, const void *_mtx);

        void setTranslate(Channel channel, float _x, float _y, float _z);

        void pushTransform(Channel channel, const void *_mtx);

        void popTransform(Channel channel);

        void moveTo(Channel channel, float _x, float _y, float _z = 0.0f);

        void moveTo(Channel channel, const bx::Vec3 &_pos);

        void lineTo(Channel channel, float _x, float _y, float _z = 0.0f);

        void lineTo(Channel channel, const bx::Vec3 &_pos);

        void close(Channel channel);

        void draw(Channel channel, const bx::Aabb &_aabb);

        void draw(Channel channel, const bx::Cylinder &_cylinder);

        void draw(Channel channel, const bx::Capsule &_capsule);

        void draw(Channel channel, const bx::Disk &_disk);

        void draw(Channel channel, const bx::Obb &_obb);

        void draw(Channel channel, const bx::Sphere &_sphere);

        void draw(Channel channel, const bx::Triangle &_triangle);

        void draw(Channel channel, const bx::Cone &_cone);

        void draw(Channel channel, GeometryHandle _handle);

        void drawLineList(Channel channel, uint32_t _numVertices,
                          const DdVertex *_vertices, uint32_t _numIndices = 0,
                          const uint16_t *_indices = NULL);

        void drawTriList(Channel channel, uint32_t _numVertices,
                         const DdVertex *_vertices, uint32_t _numIndices = 0,
                         const uint16_t *_indices = NULL);

        void drawFrustum(Channel channel, const void *_viewProj);

        void drawArc(Channel channel, Axis::Enum _axis, float _x, float _y, float _z,
                     float _radius, float _degrees);

        void drawCircle(Channel channel, const bx::Vec3 &_normal,
                        const bx::Vec3 &_center, float _radius, float _weight = 0.0f);

        void drawCircle(Channel channel, Axis::Enum _axis, float _x, float _y,
                        float _z, float _radius, float _weight = 0.0f);

        void drawQuad(Channel channel, const bx::Vec3 &_normal,
                      const bx::Vec3 &_center, float _size);

        void drawQuad(Channel channel, SpriteHandle _handle, const bx::Vec3 &_normal,
                      const bx::Vec3 &_center, float _size);

        void drawQuad(Channel channel, bgfx::TextureHandle _handle,
                      const bx::Vec3 &_normal, const bx::Vec3 &_center, float _size);

        void drawCone(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to,
                      float _radius);

        void drawCylinder(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to,
                          float _radius);

        void drawCapsule(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to,
                         float _radius);

        void drawAxis(Channel channel, float _x, float _y, float _z,
                      float _len = 1.0f, Axis::Enum _highlight = Axis::Count,
                      float _thickness = 0.0f);

        void drawGrid(Channel channel, const bx::Vec3 &_normal,
                      const bx::Vec3 &_center, uint32_t _size = 20,
                      float _step = 1.0f);

        void drawGrid(Channel channel, Axis::Enum _axis, const bx::Vec3 &_center,
                      uint32_t _size = 20, float _step = 1.0f);

        void drawOrb(Channel channel, float _x, float _y, float _z, float _radius,
                     Axis::Enum _highlight = Axis::Count);

    protected:
        HashMap<Channel, Vector<DebugDrawEncoder *>> p_DebugRenderers;
        bx::DefaultAllocator p_Allocator;
    };
} // namespace harmony
