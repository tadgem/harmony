//
// Created by liam_ on 7/6/2023.
//
#include "Rendering/Modules/Moebius/MoebiusModule.h"
#include "Rendering/Pipelines/PipelineV2.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"
#include "Rendering/Shaders/ShaderDataSources/DeferredDataSource.h"
#include "Rendering/Pipelines/PipelineStageRenderers/ScreenQuadRenderer.h"
#include "Rendering/Shaders/ShaderDataSources/BlinnPhongDataSource.h"

harmony::WeakRef<harmony::Framebuffer> harmony::Moebius::AddMoebiusToPipeline(Renderer& renderer, harmony::Ref<harmony::PipelineV2> pipeline)
{

	// Create GBuffer FB
	auto gbufferFB = pipeline->AddFramebuffer("GBuffer",
														{
																AttachmentType::RGBA32F, // 0: Position
																AttachmentType::RGBA32F, // 1: Normal
																AttachmentType::RGBA16F, // 2: Colour
																AttachmentType::RGBA32F, // 3: UVs
																AttachmentType::Depth32F // 4: Depth
														},
														Resolution::Type::FullScale);
	// Create Moebius Effect FB
	auto moebiusFB = pipeline->AddFramebuffer("Moebius FB",
													   {
															   AttachmentType::RGBA8
													   },
													   Resolution::Type::FullScale);

	// Create pipeline draw stage to render g-buffer data
	Ref<PipelineDrawStage> gBufferStage = CreateRef<PipelineDrawStage>(
			"GBufferStage",
			PipelineDrawStage::Type::PrimaryDraw,
			renderer.GetShader("DeferredGBuffer"),
			renderer.GetPipelineStageRenderer("MeshRenderer")
	);
	// Get Moebius Shader
	Ref<ShaderProgram> moebiusShader = renderer.GetShader("Moebius2").lock();

	// Create a quad renderer
	Ref<ScreenQuadRenderer> quadRenderer = CreateRef<ScreenQuadRenderer>();
	renderer.AddPipelineStageRenderer(quadRenderer);

	Ref<PipelineDrawStage> moebiusStage = CreateRef<PipelineDrawStage>(
			"Moebius",
			PipelineDrawStage::Type::PrimaryDraw,
			moebiusShader,
			quadRenderer
	);
	Ref<DeferredDataSource> deferredDataSource = CreateRef<DeferredDataSource>(gbufferFB.lock());
	renderer.AddShaderDataSource(deferredDataSource);

	moebiusStage->AddShaderDataSource(deferredDataSource);
	moebiusStage->AddShaderDataSource(renderer.GetShaderDataSource("BlinnPhong"));

	renderer.AddPipelineStage(gBufferStage);
	renderer.AddPipelineStage(moebiusStage);

	pipeline->AddPipelineStage(gbufferFB, gBufferStage);
	pipeline->AddPipelineStage(moebiusFB, moebiusStage);

	return moebiusFB;
}
