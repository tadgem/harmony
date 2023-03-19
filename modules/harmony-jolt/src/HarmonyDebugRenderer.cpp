#include "HarmonyDebugRenderer.h"
#include "Rendering/Debug/GfxDebug.h"
#include "Core/Log.hpp"
harmony::HarmonyDebugRenderer::HarmonyDebugRenderer() : JPH::DebugRenderer()
{
    Initialize();
}
harmony::HarmonyDebugRenderer::~HarmonyDebugRenderer()
{

}

void harmony::HarmonyDebugRenderer::DrawLine(JPH::RVec3Arg inFrom, JPH::RVec3Arg inTo, JPH::ColorArg inColor) 
{
    harmony::log::info("Draw Line");
}

void harmony::HarmonyDebugRenderer::DrawTriangle(JPH::RVec3Arg inV1, JPH::RVec3Arg inV2, JPH::RVec3Arg inV3,
                                              JPH::ColorArg inColor) 
{
    harmony::log::info("Draw Triangle");
}

JPH::DebugRenderer::Batch
harmony::HarmonyDebugRenderer::CreateTriangleBatch(const JPH::DebugRenderer::Triangle *inTriangles, int inTriangleCount) 
{
    harmony::log::info("Create Tri Batch");
    return JPH::DebugRenderer::Batch();
}

JPH::DebugRenderer::Batch
harmony::HarmonyDebugRenderer::CreateTriangleBatch(const JPH::DebugRenderer::Vertex *inVertices, int inVertexCount,
                                                const JPH::uint32 *inIndices, int inIndexCount)
{
    harmony::log::info("Create Tri Batch Indexed");
    return JPH::DebugRenderer::Batch();
}

void harmony::HarmonyDebugRenderer::DrawGeometry(const JPH::Mat44 &inModelMatrix, const JPH::AABox &inWorldSpaceBounds,
                                              float inLODScaleSq, JPH::ColorArg inModelColor,
                                              const JPH::DebugRenderer::GeometryRef &inGeometry,
                                              JPH::DebugRenderer::ECullMode inCullMode,
                                              JPH::DebugRenderer::ECastShadow inCastShadow,
                                              JPH::DebugRenderer::EDrawMode inDrawMode) 
{
    harmony::log::info("Draw Geometry");
}

void harmony::HarmonyDebugRenderer::DrawText3D(JPH::RVec3Arg inPosition, const std::string_view &inString,
                                            JPH::ColorArg inColor, float inHeight) 
{
    harmony::log::info("Draw Text");
}
