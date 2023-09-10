
function start()
    print("Running render setup from script")

    renderer = harmony.GetRenderer()
    local editorPipeline = renderer:GetViewPipeline("Editor")
    print("Editor Pipeline is nil? : " .. tostring(editorPipeline == nil))

    attachments = {{harmony.AttachmentType.RGBA16f}}
    local skyFB = editorPipeline:AddFramebuffer("Sky FB", attachments, harmony.ResolutionType.FullScale)
end