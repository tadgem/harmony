

using Harmony;

namespace GameTest
{
    public class TestModule : Module.IOnInit
    {
        public void Init()
        {
            Log.Info("Hello from C# TestModule");

            InitRenderer();
        }

        private void InitRenderer()
        {
            Log.Info("Getting Runtime View");
            View runtimeView = Renderer.GetView("RuntimeView");
            Log.Info("Getting Runtime View Pipeline");
            Pipeline pipeline = Renderer.GetViewPipeline(runtimeView);

            Log.Info("Creating Sky FB");
            Framebuffer skyFB = pipeline.AddFramebuffer("Sky FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            Log.Info("Creating Forward Pipeline FB");
            Framebuffer forwardFB = pipeline.AddFramebuffer("Forward FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            Log.Info("Creating VectorGraphics Pipeline FB");
            Framebuffer vectorFB = pipeline.AddFramebuffer("Vector FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            Log.Info("Creating Final Image FB");
            Framebuffer finalFB = pipeline.AddFramebuffer("Final FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            
            Log.Info("Getting Present Shader");
            ShaderProgram presentProgram = Renderer.GetShader("TexturedMesh");
            //// Moebius
            //AssetHandle[] handles = AssetMethods.GetAssetsAtPath("assets/crosshatch.png");
            //TextureAsset crosshatchTexture = AssetMethods.GetTextureAsset(handles[0]);

            //AddMoebiusToPipeline(pipeline, crosshatchTexture);

            Log.Info("Getting MeshRenderer");
            PipelineStageRenderer meshRenderer = Renderer.GetPipelineStageRenderer("MeshRenderer");

            Log.Info("Creating Normal Stage");
            PipelineDrawStage normalStage = Renderer.CreatePipelineDrawStage("NormalStage", Renderer.GetShader("Normal"), meshRenderer);
            Log.Info("Creating TexturedMesh Stage");
            PipelineDrawStage texturedMeshStage = Renderer.CreatePipelineDrawStage("TexturedMeshStage", Renderer.GetShader("TexturedMesh"), meshRenderer);
            Log.Info("Creating Blinn Phong Stage");
            PipelineDrawStage blinnPhongStage = Renderer.CreatePipelineDrawStage("BlinnPhongTexturedStage", Renderer.GetShader("BlinnPhongTextured"), meshRenderer);
            Log.Info("Creating Blinn Phong Data Source");
            blinnPhongStage.AddShaderDataSource(Renderer.CreateBlinnPhongDataSource());

            Log.Info("Creating Sky Stage");
            SkyStage skyStage = Renderer.CreateSkyStage();
            Log.Info("Creating Vector Graphics Stage");
            VectorGraphicsStage vectorGraphicsStage = Renderer.CreateVectorGraphicsStage(VectorGraphics.Layer.One);
            Log.Info("Creating DebugDraw Stage");
            DebugDrawStage debugDrawStage = Renderer.CreateDebugDrawStage(DebugDrawChannel.Game);

            Log.Info("Creating Sky Stage FB Array");
            Framebuffer[] drawSkyStageFBs = new[] { skyFB };
            Log.Info("Creating Forward FB Array");
            Framebuffer[] drawForwardFBs = new[] { forwardFB };
            Log.Info("Creating Vector FB Array");
            Framebuffer[] drawVectorFBs = new[] { vectorFB };

            Log.Info("Creating DrawScreenTextureStage : Sky");
            DrawScreenTextureStage drawSkyStage = Renderer.CreateDrawScreenTextureStage(pipeline, presentProgram, AttachmentType.RGBA8, drawSkyStageFBs);
            Log.Info("Creating DrawScreenTextureStage : Forward Pipeline");
            DrawScreenTextureStage drawForwardStage = Renderer.CreateDrawScreenTextureStage(pipeline,presentProgram, AttachmentType.RGBA8, drawForwardFBs);
            Log.Info("Creating DrawScreenTextureStage : Vector");
            DrawScreenTextureStage drawVectorStage = Renderer.CreateDrawScreenTextureStage(pipeline, presentProgram, AttachmentType.RGBA8, drawVectorFBs);
            // DrawScreenTextureStage drawMoebiusStage = pipeline.CreateDrawScreenTextureStage(presentProgram, AttachmentType.RGBA8, new[] { moebiusFB });

            Log.Info("Adding Sky Stage to Sky FB");
            pipeline.AddStage(skyFB, skyStage);

            Log.Info("Adding DebugDraw Stage to Forward FB");
            pipeline.AddStage(forwardFB, debugDrawStage);
            Log.Info("Adding Normal Stage to Forward FB");
            pipeline.AddStage(forwardFB, normalStage);
            Log.Info("Adding TexturedMesh Stage to Forward FB");
            pipeline.AddStage(forwardFB, texturedMeshStage);
            Log.Info("Adding Blinn Phong to Forward FB");
            pipeline.AddStage(forwardFB, blinnPhongStage);
            Log.Info("Adding VectorGraphics Stage to Vector FB");
            pipeline.AddStage(vectorFB, vectorGraphicsStage);

            Log.Info("Adding Draw Sky to Final Image FB");
            pipeline.AddStage(finalFB, drawSkyStage);
            Log.Info("Adding Draw Forward Pipeline to Final Image FB");
            pipeline.AddStage(finalFB, drawForwardStage);
            // pipeline.AddStage(finalFB, drawMoebiusStage);
            Log.Info("Adding Draw VectorGraphics to Final Image FB");
            pipeline.AddStage(finalFB, drawVectorStage);

            Log.Info("Setting Output Framebuffer to Final Image FB");
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
