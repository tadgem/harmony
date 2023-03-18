#include "HarmonyDebugRenderer.h"

harmony::JoltDebugRenderer::~JoltDebugRenderer() {

}

void harmony::JoltDebugRenderer::DrawLine(JPH::RVec3Arg inFrom, JPH::RVec3Arg inTo, JPH::ColorArg inColor) {

}

void harmony::JoltDebugRenderer::DrawTriangle(JPH::RVec3Arg inV1, JPH::RVec3Arg inV2, JPH::RVec3Arg inV3,
                                              JPH::ColorArg inColor) {

}

JPH::DebugRenderer::Batch
harmony::JoltDebugRenderer::CreateTriangleBatch(const JPH::DebugRenderer::Triangle *inTriangles, int inTriangleCount) {
    return JPH::DebugRenderer::Batch();
}

JPH::DebugRenderer::Batch
harmony::JoltDebugRenderer::CreateTriangleBatch(const JPH::DebugRenderer::Vertex *inVertices, int inVertexCount,
                                                const JPH::uint32 *inIndices, int inIndexCount) {
    return JPH::DebugRenderer::Batch();
}

void harmony::JoltDebugRenderer::DrawGeometry(const JPH::Mat44 &inModelMatrix, const JPH::AABox &inWorldSpaceBounds,
                                              float inLODScaleSq, JPH::ColorArg inModelColor,
                                              const JPH::DebugRenderer::GeometryRef &inGeometry,
                                              JPH::DebugRenderer::ECullMode inCullMode,
                                              JPH::DebugRenderer::ECastShadow inCastShadow,
                                              JPH::DebugRenderer::EDrawMode inDrawMode) {

}

void harmony::JoltDebugRenderer::DrawText3D(JPH::RVec3Arg inPosition, const std::string_view &inString,
                                            JPH::ColorArg inColor, float inHeight) {

}
