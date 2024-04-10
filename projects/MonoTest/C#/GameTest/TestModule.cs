

using Harmony;

namespace GameTest
{
    public class TestModule : Module.IOnInit
    {
        public void Init()
        {
            Log.Info("Hello from C# TestModule");

            InitRenderer();

            Log.Info($"Goodbye from C# TestModule");
        }

        private void InitRenderer()
        {
            View runtimeView = Renderer.GetView("RuntimeView");
            Pipeline pipeline = Renderer.GetViewPipeline(runtimeView);

            Framebuffer skyFB = pipeline.AddFramebuffer("Sky FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            Framebuffer forwardFB = pipeline.AddFramebuffer("Forward FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            Framebuffer vectorFB = pipeline.AddFramebuffer("Vector FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            Framebuffer finalFB = pipeline.AddFramebuffer("Final FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            
            ShaderProgram presentProgram = Renderer.GetShader("TexturedMesh");
            //// Moebius
            // AssetHandle[] handles = AssetMethods.GetAssetsAtPath("assets/crosshatch.png");
            // TextureAsset crosshatchTexture = AssetMethods.GetTextureAsset(handles[0]);

            //AddMoebiusToPipeline(pipeline, crosshatchTexture);

            PipelineStageRenderer meshRenderer = Renderer.GetPipelineStageRenderer("MeshRenderer");

            PipelineDrawStage normalStage = Renderer.CreatePipelineDrawStage("NormalStage", Renderer.GetShader("Normal"), meshRenderer);
            PipelineDrawStage texturedMeshStage = Renderer.CreatePipelineDrawStage("TexturedMeshStage", Renderer.GetShader("TexturedMesh"), meshRenderer);
            PipelineDrawStage blinnPhongStage = Renderer.CreatePipelineDrawStage("BlinnPhongTexturedStage", Renderer.GetShader("BlinnPhongTextured"), meshRenderer);
            blinnPhongStage.AddShaderDataSource(Renderer.CreateBlinnPhongDataSource());

            SkyStage skyStage = Renderer.CreateSkyStage();
            VectorGraphicsStage vectorGraphicsStage = Renderer.CreateVectorGraphicsStage(VectorGraphics.Layer.One);
            DebugDrawStage debugDrawStage = Renderer.CreateDebugDrawStage(DebugDrawChannel.Game);

            Framebuffer[] drawSkyStageFBs = new[] { skyFB };
            Framebuffer[] drawForwardFBs = new[] { forwardFB };
            Framebuffer[] drawVectorFBs = new[] { vectorFB };

            DrawScreenTextureStage drawSkyStage = Renderer.CreateDrawScreenTextureStage(pipeline, presentProgram, AttachmentType.RGBA8, drawSkyStageFBs);
            DrawScreenTextureStage drawForwardStage = Renderer.CreateDrawScreenTextureStage(pipeline,presentProgram, AttachmentType.RGBA8, drawForwardFBs);
            DrawScreenTextureStage drawVectorStage = Renderer.CreateDrawScreenTextureStage(pipeline, presentProgram, AttachmentType.RGBA8, drawVectorFBs);
            // DrawScreenTextureStage drawMoebiusStage = pipeline.CreateDrawScreenTextureStage(presentProgram, AttachmentType.RGBA8, new[] { moebiusFB });

            pipeline.AddStage(skyFB, skyStage);

            pipeline.AddStage(forwardFB, debugDrawStage);
            pipeline.AddStage(forwardFB, normalStage);
            pipeline.AddStage(forwardFB, texturedMeshStage);
            pipeline.AddStage(forwardFB, blinnPhongStage);
            pipeline.AddStage(vectorFB, vectorGraphicsStage);

            pipeline.AddStage(finalFB, drawSkyStage);
            pipeline.AddStage(finalFB, drawForwardStage);
            // pipeline.AddStage(finalFB, drawMoebiusStage);
            pipeline.AddStage(finalFB, drawVectorStage);

            pipeline.SetOutputFramebuffer(finalFB);
        }

        private void AddMoebiusToPipeline(Pipeline pipeline, TextureAsset crossHatchTexture)
        {
            // Create GBuffer FB
            Framebuffer gBufferFB = pipeline.AddFramebuffer("GBuffer", new[] 
                                              {
                                                AttachmentType.RGBA32F, // 0: Position
                                                AttachmentType.RGBA32F, // 1: Normal
                                                AttachmentType.RGBA16F, // 2: Colour
                                                AttachmentType.RGBA32F, // 3: UVs
                                                AttachmentType.Depth32F // 4: Depth
                                              },
                                              Resolution.Type.FullScale);
            // Create Moebius Effect FB
            Framebuffer moebiusFB = pipeline.AddFramebuffer("Moebius FB", new[]
            {
                AttachmentType.RGBA8
            },
            Resolution.Type.FullScale);

            //// Create deferred gbuffer draw stage
            PipelineDrawStage gBufferStage = Renderer.CreatePipelineDrawStage("GBufferStage", Renderer.GetShader("DeferredGBuffer"), Renderer.GetPipelineStageRenderer("MeshRenderer"));
            //// Create a screen quad renderer
            ScreenQuadRenderer screenQuadRenderer = Renderer.CreateScreenQuadRenderer();
            //// create moebius draw stage (moebius shader, quad renderer)
            PipelineDrawStage moebiusStage = Renderer.CreatePipelineDrawStage("MoebiusStage", Renderer.GetShader("Moebius2"), screenQuadRenderer);
            //// Create deferred data source
            ShaderDataSource deferredDataSource = Renderer.CreateDeferredDataSource(pipeline, gBufferFB);
            // Blinn Phong lighting params
            ShaderDataSource blinnPhongDataSource = Renderer.CreateBlinnPhongDataSource();
            //// Create crosshatch texture data source;
            ShaderDataSource crosshatchTextureSource = Renderer.CreateTextureAssetSource(5, "u_crossHatch", crossHatchTexture);

            moebiusStage.AddShaderDataSource(deferredDataSource);
            moebiusStage.AddShaderDataSource(blinnPhongDataSource);
            moebiusStage.AddShaderDataSource(crosshatchTextureSource);

            pipeline.AddStage(gBufferFB, gBufferStage);
            pipeline.AddStage(moebiusFB, moebiusStage);

        }
    }
}
