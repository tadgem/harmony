local viewEntity = nil
local view = nil
local t = nil
local speed = 50.0

function GetView()
    if view == nil then
        view = harmony.GetView("RuntimeView")
        if(view == nil) then
            return
        end
        t = viewEntity:GetTransform()
        currentHeight = t.position.y
    end
end


function start()
    viewEntity = harmony.GetEntity()
end

function update()
    deltaTime = time.GetFrameTime() * speed;
    GetView()
    viewEntity = harmony.GetEntity()
    t = viewEntity:GetTransform()
    t.euler.x = t.euler.x + deltaTime
end