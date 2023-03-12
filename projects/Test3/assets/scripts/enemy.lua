local view = nil
local viewTransform = nil
local enemyMoveDir = math.vec3:new()
local enemySpeed = 0.0

function start()
    print("enemy.lua : start")
    enemySpeed = math.random()
end

function GetView()
    if view == nil then
        view = harmony.GetView("RuntimeView")
        if view == nil then
            return
        end
        viewEntity = harmony.GetViewEntity(view)
        viewTransform = viewEntity:GetTransform()
    end
end

function update()
    GetView()
    deltaTime = time.GetFrameTime();

    local finalSpeed = deltaTime * enemySpeed

    thisTransform = this_entity:GetTransform()
    enemyMoveDir = math.normVec3(math.subVec3(viewTransform.position, thisTransform.position))

    thisTransform.position = math.addVec3(thisTransform.position, math.mulVec3f(enemyMoveDir, finalSpeed))
end

function cleanup()
    print("enemy.lua : Cleanup")
end