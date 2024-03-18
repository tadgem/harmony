#include <optick.h>
#include "Rendering/Debug/GfxDebug.h"

harmony::GfxDebug::GfxDebug() {
    OPTICK_EVENT();
    p_DebugRenderers.emplace(Channel::Editor, Vector<DebugDrawEncoder *>());
    p_DebugRenderers.emplace(Channel::Game, Vector<DebugDrawEncoder *>());

    ddInit(&p_Allocator);
}

harmony::GfxDebug::~GfxDebug() {
    OPTICK_EVENT();
    ddShutdown();
}

harmony::GfxDebug *harmony::GfxDebug::Get() {
    OPTICK_EVENT();
    if (p_Instance == nullptr) {
        p_Instance = new GfxDebug();
    }

    return p_Instance;
}

DebugDrawEncoder *harmony::GfxDebug::AddViewChannel(Channel channel) {
    OPTICK_EVENT();
    DebugDrawEncoder *renderer = new DebugDrawEncoder();
    p_DebugRenderers[channel].emplace_back(renderer);
    return renderer;
}

void harmony::GfxDebug::RemoveViewChannel(Channel channel, DebugDrawEncoder *renderer) {
    OPTICK_EVENT();
    int indexToRemove = -1;
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        if (p_DebugRenderers[channel][i] == renderer) {
            indexToRemove = i;
        }
    }

    if (indexToRemove >= 0) {
        p_DebugRenderers[channel].erase(p_DebugRenderers[channel].begin() + indexToRemove);
        delete renderer;
        renderer = nullptr;
    }

}

void harmony::GfxDebug::push(Channel channel) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->push();
    }
}

void harmony::GfxDebug::pop(Channel channel) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->pop();
    }
}

void harmony::GfxDebug::setDepthTestLess(Channel channel, bool _depthTestLess) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setDepthTestLess(_depthTestLess);
    }
}

void harmony::GfxDebug::setState(Channel channel, bool _depthTest, bool _depthWrite, bool _clockwise) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setState(_depthTest, _depthWrite, _clockwise);
    }
}

void harmony::GfxDebug::setColor(Channel channel, uint32_t _abgr) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setColor(_abgr);
    }
}

void harmony::GfxDebug::setLod(Channel channel, uint8_t _lod) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setLod(_lod);
    }
}

void harmony::GfxDebug::setWireframe(Channel channel, bool _wireframe) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setWireframe(_wireframe);
    }
}

void harmony::GfxDebug::setStipple(Channel channel, bool _stipple, float _scale, float _offset) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setStipple(_stipple, _scale, _offset);
    }
}

void harmony::GfxDebug::setSpin(Channel channel, float _spin) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setSpin(_spin);
    }
}

void harmony::GfxDebug::setTransform(Channel channel, const void *_mtx) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setTransform(_mtx);
    }
}

void harmony::GfxDebug::setTranslate(Channel channel, float _x, float _y, float _z) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setTranslate(_x, _y, _z);
    }
}

void harmony::GfxDebug::pushTransform(Channel channel, const void *_mtx) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->pushTransform(_mtx);
    }
}

void harmony::GfxDebug::popTransform(Channel channel) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->popTransform();
    }
}

void harmony::GfxDebug::moveTo(Channel channel, float _x, float _y, float _z) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->moveTo(_x, _y, _z);
    }
}

void harmony::GfxDebug::moveTo(Channel channel, const bx::Vec3 &_pos) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->moveTo(_pos);
    }
}

void harmony::GfxDebug::lineTo(Channel channel, float _x, float _y, float _z) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->lineTo(_x, _y, _z);
    }
}

void harmony::GfxDebug::lineTo(Channel channel, const bx::Vec3 &_pos) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->lineTo(_pos);
    }
}

void harmony::GfxDebug::close(Channel channel) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->close();
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Aabb &_aabb) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_aabb);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Cylinder &_cylinder) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_cylinder);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Capsule &_capsule) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_capsule);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Disk &_disk) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_disk);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Obb &_obb) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_obb);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Sphere &_sphere) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_sphere);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Triangle &_triangle) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_triangle);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Cone &_cone) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_cone);
    }
}

void harmony::GfxDebug::draw(Channel channel, GeometryHandle _handle) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_handle);
    }
}

void
harmony::GfxDebug::drawLineList(Channel channel, uint32_t _numVertices, const DdVertex *_vertices, uint32_t _numIndices,
                                const uint16_t *_indices) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawLineList(_numVertices, _vertices, _numIndices, _indices);
    }
}

void
harmony::GfxDebug::drawTriList(Channel channel, uint32_t _numVertices, const DdVertex *_vertices, uint32_t _numIndices,
                               const uint16_t *_indices) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawTriList(_numVertices, _vertices, _numIndices, _indices);
    }
}

void harmony::GfxDebug::drawFrustum(Channel channel, const void *_viewProj) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawFrustum(_viewProj);
    }
}

void harmony::GfxDebug::drawArc(Channel channel, Axis::Enum _axis, float _x, float _y, float _z, float _radius,
                                float _degrees) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawArc(_axis, _x, _y, _z, _radius, _degrees);
    }
}

void harmony::GfxDebug::drawCircle(Channel channel, const bx::Vec3 &_normal, const bx::Vec3 &_center, float _radius,
                                   float _weight) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCircle(_normal, _center, _radius, _weight);
    }
}

void harmony::GfxDebug::drawCircle(Channel channel, Axis::Enum _axis, float _x, float _y, float _z, float _radius,
                                   float _weight) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCircle(_axis, _x, _y, _z, _radius, _weight);
    }
}

void harmony::GfxDebug::drawQuad(Channel channel, const bx::Vec3 &_normal, const bx::Vec3 &_center, float _size) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawQuad(_normal, _center, _size);
    }
}

void
harmony::GfxDebug::drawQuad(Channel channel, SpriteHandle _handle, const bx::Vec3 &_normal, const bx::Vec3 &_center,
                            float _size) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawQuad(_handle, _normal, _center, _size);
    }
}

void harmony::GfxDebug::drawQuad(Channel channel, bgfx::TextureHandle _handle, const bx::Vec3 &_normal,
                                 const bx::Vec3 &_center, float _size) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawQuad(_handle, _normal, _center, _size);
    }
}

void harmony::GfxDebug::drawCone(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to, float _radius) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCone(_from, _to, _radius);
    }
}

void harmony::GfxDebug::drawCylinder(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to, float _radius) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCylinder(_from, _to, _radius);
    }
}

void harmony::GfxDebug::drawCapsule(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to, float _radius) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCapsule(_from, _to, _radius);
    }
}

void harmony::GfxDebug::drawAxis(Channel channel, float _x, float _y, float _z, float _len, Axis::Enum _highlight,
                                 float _thickness) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawAxis(_x, _y, _z, _len, _highlight, _thickness);
    }
}

void harmony::GfxDebug::drawGrid(Channel channel, const bx::Vec3 &_normal, const bx::Vec3 &_center, uint32_t _size,
                                 float _step) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawGrid(_normal, _center, _size, _step);
    }
}

void
harmony::GfxDebug::drawGrid(Channel channel, Axis::Enum _axis, const bx::Vec3 &_center, uint32_t _size, float _step) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawGrid(_axis, _center, _size, _step);
    }
}

void harmony::GfxDebug::drawOrb(Channel channel, float _x, float _y, float _z, float _radius, Axis::Enum _highlight) {
    OPTICK_EVENT();
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawOrb(_x, _y, _z, _radius, _highlight);
    }
}
