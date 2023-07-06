//
// Created by liam_ on 7/6/2023.
//
#include "Rendering/Modules/Moebius/MoebiusModule.h"
#include "Rendering/Pipelines/PipelineV2.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"
harmony::WeakRef<harmony::Framebuffer> harmony::Moebius::AddMoebiusToPipeline(Renderer& renderer, harmony::Ref<harmony::PipelineV2> pipeline)
{


	auto deferredFB = pipeline->AddFramebuffer("Deferred FB",
														{
																AttachmentType::RGBA32F, // 0: Position
																AttachmentType::RGBA32F, // 1: Normal
																AttachmentType::RGBA16F //  2: Colour
														},
														Resolution::Type::FullScale);

	auto moebiusFB = pipeline->AddFramebuffer("Moebius FB",
													   {
															   AttachmentType::RGBA8
													   },
													   Resolution::Type::FullScale);

	Ref<PipelineDrawStage> gBufferStage = CreateRef<PipelineDrawStage>(
			"DeferredGBuffer",
			PipelineDrawStage::Type::PrimaryDraw,
			renderer.GetShader("DeferredGBuffer"),
			renderer.GetPipelineStageRenderer("MeshRenderer")
	);

	renderer.AddPipelineStage(gBufferStage);

	pipeline->AddPipelineStage(deferredFB, gBufferStage);

	return moebiusFB;
}
