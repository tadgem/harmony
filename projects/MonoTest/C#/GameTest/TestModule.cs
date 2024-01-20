

using Harmony;

namespace GameTest
{
    public class TestModule : Module.IOnInit
    {
        public void Init()
        {
            Log.Info("Hello from C# TestModule");

            // InitRenderer();
        }

        private void InitRenderer()
        {
            View runtimeView = Renderer.GetView("RuntimeView");
            Pipeline pipeline = Renderer.GetViewPipeline(runtimeView);

            Framebuffer skyFB = pipeline.PipelineAddFramebuffer("Sky FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            Framebuffer forwardFB = pipeline.PipelineAddFramebuffer("Forward FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);
            Framebuffer vectorFB = pipeline.PipelineAddFramebuffer("Vector FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);

            // Moebius

            AssetHandle[] handles = AssetMethods.GetAssetsAtPath("assets/crosshatch.png");
            TextureAsset crosshatchTexture = AssetMethods.GetTextureAsset(handles[0]);

            Framebuffer finalFB = pipeline.PipelineAddFramebuffer("Final FB", new[] { AttachmentType.RGBA16F, AttachmentType.Depth32F }, Resolution.Type.FullScale);

            ShaderProgram presentProgram = Renderer.GetShader("Present");

            // Create draw stage for each framebuffer...

            pipeline.PipelineAddStage(skyFB, Renderer.GetPipelineStage("SkyStage"));

            pipeline.PipelineAddStage(forwardFB, Renderer.GetPipelineStage("DebugDrawStage"));
            pipeline.PipelineAddStage(forwardFB, Renderer.GetPipelineStage("NormalStage"));
            pipeline.PipelineAddStage(forwardFB, Renderer.GetPipelineStage("TexturedMeshStage"));
            pipeline.PipelineAddStage(forwardFB, Renderer.GetPipelineStage("BlinnPhongTextured"));
            pipeline.PipelineAddStage(vectorFB, Renderer.GetPipelineStage("VectorGraphicsStage"));

            // Add draw stages to output framebuffer

            pipeline.PipelineSetOutputFramebuffer(finalFB);
        }

        private void AddMoebiusToPipeline(Pipeline pipeline, TextureAsset crossHatchTexture)
        {
            // Create GBuffer FB
            Framebuffer gbufferFB = pipeline.PipelineAddFramebuffer("GBuffer", new[] 
                                              {
                                                AttachmentType.RGBA32F, // 0: Position
                                                AttachmentType.RGBA32F, // 1: Normal
                                                AttachmentType.RGBA16F, // 2: Colour
                                                AttachmentType.RGBA32F, // 3: UVs
                                                AttachmentType.Depth32F // 4: Depth
                                              },
                                              Resolution.Type.FullScale);
            // Create Moebius Effect FB
            Framebuffer moebiusFB = pipeline.PipelineAddFramebuffer("Moebius FB", new[]
            {
                AttachmentType.RGBA8
            },
            Resolution.Type.FullScale);

            // Create deferred gbuffer draw stage

            ShaderProgram moebiusShader = Renderer.GetShader("Moebius2");
            ShaderDataSource blinnPhongDataSource = Renderer.GetShaderDataSource("BlinnPhong");

            // Create a screen quad renderer
            
            // create moebius draw stage (moebius shader, quad renderer)
            // Create deferred data source
            // Create crosshatch texture data source;
            // add deferred, blinn phong and crosshatch sources to moebius stage
            // Add gBuffer stage to gbuffer fb, moebius stage to moebius fb

            
        }
    }
}
