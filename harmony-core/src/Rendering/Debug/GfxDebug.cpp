#include "Rendering/Debug/GfxDebug.h"

harmony::GfxDebug::GfxDebug() {
    p_DebugRenderers.emplace(Channel::Editor, std::vector<DebugDrawEncoder *>());
    p_DebugRenderers.emplace(Channel::Game, std::vector<DebugDrawEncoder *>());

    ddInit(&p_Allocator);
}

harmony::GfxDebug::~GfxDebug() {
    ddShutdown();
}

harmony::GfxDebug *harmony::GfxDebug::Get() {
    if (p_Instance == nullptr) {
        p_Instance = new GfxDebug();
    }

    return p_Instance;
}

DebugDrawEncoder *harmony::GfxDebug::AddViewChannel(Channel channel) {
    DebugDrawEncoder *renderer = new DebugDrawEncoder();
    p_DebugRenderers[channel].emplace_back(renderer);
    return renderer;
}

void harmony::GfxDebug::RemoveViewChannel(Channel channel, DebugDrawEncoder *renderer) {
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
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->push();
    }
}

void harmony::GfxDebug::pop(Channel channel) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->pop();
    }
}

void harmony::GfxDebug::setDepthTestLess(Channel channel, bool _depthTestLess) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setDepthTestLess(_depthTestLess);
    }
}

void harmony::GfxDebug::setState(Channel channel, bool _depthTest, bool _depthWrite, bool _clockwise) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setState(_depthTest, _depthWrite, _clockwise);
    }
}

void harmony::GfxDebug::setColor(Channel channel, uint32_t _abgr) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setColor(_abgr);
    }
}

void harmony::GfxDebug::setLod(Channel channel, uint8_t _lod) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setLod(_lod);
    }
}

void harmony::GfxDebug::setWireframe(Channel channel, bool _wireframe) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setWireframe(_wireframe);
    }
}

void harmony::GfxDebug::setStipple(Channel channel, bool _stipple, float _scale, float _offset) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setStipple(_stipple, _scale, _offset);
    }
}

void harmony::GfxDebug::setSpin(Channel channel, float _spin) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setSpin(_spin);
    }
}

void harmony::GfxDebug::setTransform(Channel channel, const void *_mtx) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setTransform(_mtx);
    }
}

void harmony::GfxDebug::setTranslate(Channel channel, float _x, float _y, float _z) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->setTranslate(_x, _y, _z);
    }
}

void harmony::GfxDebug::pushTransform(Channel channel, const void *_mtx) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->pushTransform(_mtx);
    }
}

void harmony::GfxDebug::popTransform(Channel channel) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->popTransform();
    }
}

void harmony::GfxDebug::moveTo(Channel channel, float _x, float _y, float _z) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->moveTo(_x, _y, _z);
    }
}

void harmony::GfxDebug::moveTo(Channel channel, const bx::Vec3 &_pos) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->moveTo(_pos);
    }
}

void harmony::GfxDebug::lineTo(Channel channel, float _x, float _y, float _z) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->lineTo(_x, _y, _z);
    }
}

void harmony::GfxDebug::lineTo(Channel channel, const bx::Vec3 &_pos) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->lineTo(_pos);
    }
}

void harmony::GfxDebug::close(Channel channel) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->close();
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Aabb &_aabb) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_aabb);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Cylinder &_cylinder) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_cylinder);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Capsule &_capsule) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_capsule);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Disk &_disk) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_disk);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Obb &_obb) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_obb);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Sphere &_sphere) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_sphere);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Triangle &_triangle) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_triangle);
    }
}

void harmony::GfxDebug::draw(Channel channel, const bx::Cone &_cone) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_cone);
    }
}

void harmony::GfxDebug::draw(Channel channel, GeometryHandle _handle) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->draw(_handle);
    }
}

void
harmony::GfxDebug::drawLineList(Channel channel, uint32_t _numVertices, const DdVertex *_vertices, uint32_t _numIndices,
                                const uint16_t *_indices) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawLineList(_numVertices, _vertices, _numIndices, _indices);
    }
}

void
harmony::GfxDebug::drawTriList(Channel channel, uint32_t _numVertices, const DdVertex *_vertices, uint32_t _numIndices,
                               const uint16_t *_indices) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawTriList(_numVertices, _vertices, _numIndices, _indices);
    }
}

void harmony::GfxDebug::drawFrustum(Channel channel, const void *_viewProj) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawFrustum(_viewProj);
    }
}

void harmony::GfxDebug::drawArc(Channel channel, Axis::Enum _axis, float _x, float _y, float _z, float _radius,
                                float _degrees) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawArc(_axis, _x, _y, _z, _radius, _degrees);
    }
}

void harmony::GfxDebug::drawCircle(Channel channel, const bx::Vec3 &_normal, const bx::Vec3 &_center, float _radius,
                                   float _weight) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCircle(_normal, _center, _radius, _weight);
    }
}

void harmony::GfxDebug::drawCircle(Channel channel, Axis::Enum _axis, float _x, float _y, float _z, float _radius,
                                   float _weight) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCircle(_axis, _x, _y, _z, _radius, _weight);
    }
}

void harmony::GfxDebug::drawQuad(Channel channel, const bx::Vec3 &_normal, const bx::Vec3 &_center, float _size) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawQuad(_normal, _center, _size);
    }
}

void
harmony::GfxDebug::drawQuad(Channel channel, SpriteHandle _handle, const bx::Vec3 &_normal, const bx::Vec3 &_center,
                            float _size) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawQuad(_handle, _normal, _center, _size);
    }
}

void harmony::GfxDebug::drawQuad(Channel channel, bgfx::TextureHandle _handle, const bx::Vec3 &_normal,
                                 const bx::Vec3 &_center, float _size) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawQuad(_handle, _normal, _center, _size);
    }
}

void harmony::GfxDebug::drawCone(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to, float _radius) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCone(_from, _to, _radius);
    }
}

void harmony::GfxDebug::drawCylinder(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to, float _radius) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCylinder(_from, _to, _radius);
    }
}

void harmony::GfxDebug::drawCapsule(Channel channel, const bx::Vec3 &_from, const bx::Vec3 &_to, float _radius) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawCapsule(_from, _to, _radius);
    }
}

void harmony::GfxDebug::drawAxis(Channel channel, float _x, float _y, float _z, float _len, Axis::Enum _highlight,
                                 float _thickness) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawAxis(_x, _y, _z, _len, _highlight, _thickness);
    }
}

void harmony::GfxDebug::drawGrid(Channel channel, const bx::Vec3 &_normal, const bx::Vec3 &_center, uint32_t _size,
                                 float _step) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawGrid(_normal, _center, _size, _step);
    }
}

void
harmony::GfxDebug::drawGrid(Channel channel, Axis::Enum _axis, const bx::Vec3 &_center, uint32_t _size, float _step) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawGrid(_axis, _center, _size, _step);
    }
}

void harmony::GfxDebug::drawOrb(Channel channel, float _x, float _y, float _z, float _radius, Axis::Enum _highlight) {
    for (int i = 0; i < p_DebugRenderers[channel].size(); i++) {
        p_DebugRenderers[channel][i]->drawOrb(_x, _y, _z, _radius, _highlight);
    }
}
