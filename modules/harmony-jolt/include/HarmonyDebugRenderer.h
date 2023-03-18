#pragma once
#include "Jolt/Jolt.h"
#include "Jolt/Renderer/DebugRenderer.h"

namespace harmony
{
    class JoltDebugRenderer : public JPH::DebugRenderer
    {
    public:
        ~JoltDebugRenderer() override;

        void DrawLine(JPH::RVec3Arg inFrom, JPH::RVec3Arg inTo, JPH::ColorArg inColor) override;

        void DrawTriangle(JPH::RVec3Arg inV1, JPH::RVec3Arg inV2, JPH::RVec3Arg inV3, JPH::ColorArg inColor) override;

        Batch CreateTriangleBatch(const Triangle *inTriangles, int inTriangleCount) override;

        Batch CreateTriangleBatch(const Vertex *inVertices, int inVertexCount, const JPH::uint32 *inIndices,
                                  int inIndexCount) override;

        void DrawGeometry(const JPH::Mat44 &inModelMatrix, const JPH::AABox &inWorldSpaceBounds, float inLODScaleSq,
                          JPH::ColorArg inModelColor, const GeometryRef &inGeometry, ECullMode inCullMode,
                          ECastShadow inCastShadow, EDrawMode inDrawMode) override;

        void DrawText3D(JPH::RVec3Arg inPosition, const std::string_view &inString, JPH::ColorArg inColor,
                        float inHeight) override;

    public:

    };
}