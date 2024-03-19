#include "HarmonyDebugRenderer.h"
#include "Rendering/Debug/GfxDebug.h"
#include "Core/Log.hpp"
#include "Rendering/Mesh.h"

harmony::HarmonyDebugRenderer::HarmonyDebugRenderer() : JPH::DebugRenderer() {
    Initialize();
}

harmony::HarmonyDebugRenderer::~HarmonyDebugRenderer() {

}

void harmony::HarmonyDebugRenderer::DrawLine(JPH::RVec3Arg inFrom, JPH::RVec3Arg inTo, JPH::ColorArg inColor) {
    harmony::log::info("JoltDebugRenderer : Implement : Draw Line");
}

void harmony::HarmonyDebugRenderer::DrawTriangle(JPH::RVec3Arg inV1, JPH::RVec3Arg inV2, JPH::RVec3Arg inV3,
                                                 JPH::ColorArg inColor, ECastShadow inCastShadow) {
    harmony::log::info("JoltDebugRenderer : Implement : Draw Triangle");
}

JPH::DebugRenderer::Batch
harmony::HarmonyDebugRenderer::CreateTriangleBatch(const JPH::DebugRenderer::Triangle *inTriangles,
                                                   int inTriangleCount) {
    harmony::log::info("JoltDebugRenderer : Implement : Create Tri Batch");
    return JPH::DebugRenderer::Batch();
}

JPH::DebugRenderer::Batch
harmony::HarmonyDebugRenderer::CreateTriangleBatch(const JPH::DebugRenderer::Vertex *inVertices, int inVertexCount,
                                                   const JPH::uint32 *inIndices, int inIndexCount) {
    harmony::log::info("JoltDebugRenderer : Create Tri Batch Indexed");
    auto batch = new HarmonyGeometryBatch(inVertices, inVertexCount, inIndices, inIndexCount);

    return batch;
}

void harmony::HarmonyDebugRenderer::DrawGeometry(const JPH::Mat44 &inModelMatrix, const JPH::AABox &inWorldSpaceBounds,
                                                 float inLODScaleSq, JPH::ColorArg inModelColor,
                                                 const JPH::DebugRenderer::GeometryRef &inGeometry,
                                                 JPH::DebugRenderer::ECullMode inCullMode,
                                                 JPH::DebugRenderer::ECastShadow inCastShadow,
                                                 JPH::DebugRenderer::EDrawMode inDrawMode) {
    int maxLod = inGeometry->mLODs.size() - 1;
    HarmonyGeometryBatch *batch = static_cast<HarmonyGeometryBatch *>(inGeometry->mLODs[maxLod].mTriangleBatch.GetPtr());
    GfxDebug::Get()->setColor(GfxDebug::Editor, inModelColor.GetUInt32());
    GfxDebug::Get()->setTransform(GfxDebug::Editor, (const void *) &inModelMatrix);
    GfxDebug::Get()->drawTriList(GfxDebug::Editor, batch->m_NumVertices, batch->m_Vertices, batch->m_NumIndices,
                                 batch->m_Indices);
}

void harmony::HarmonyDebugRenderer::DrawText3D(JPH::RVec3Arg inPosition, const StringView &inString,
                                               JPH::ColorArg inColor, float inHeight) {
    harmony::log::info("JoltDebugRenderer : Implement : Draw Text");
}

harmony::HarmonyDebugRenderer::HarmonyGeometryBatch::HarmonyGeometryBatch(const Vertex *inVertices, int inVertexCount,
                                                                          const JPH::uint32 *inIndices,
                                                                          int inIndexCount) {
    m_Vertices = new DdVertex[inVertexCount];
    m_Indices = new uint16_t[inIndexCount];
    m_NumVertices = inVertexCount;
    m_NumIndices = inIndexCount;

    for (int i = 0; i < inVertexCount; i++) {
        m_Vertices[i].x = inVertices[i].mPosition.x;
        m_Vertices[i].y = inVertices[i].mPosition.y;
        m_Vertices[i].z = inVertices[i].mPosition.z;
        m_Color = inVertices[i].mColor.mU32;
    }

    for (int i = 0; i < inIndexCount; i++) {
        m_Indices[i] = inIndices[i];
    }

}

void harmony::HarmonyDebugRenderer::HarmonyGeometryBatch::AddRef() {
}

void harmony::HarmonyDebugRenderer::HarmonyGeometryBatch::Release() {
}
