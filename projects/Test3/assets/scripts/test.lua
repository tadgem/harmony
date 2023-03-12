local e                   = nil 
local speed               =10.0
local rotationBase        = 180.0
local rotationMulti       = 1.0;
local rotationThreshold   = 0.0
local deadZone            = 0.1
local limitX              = 60
local lowerLimitX         = 0.0 - limitX

local groundHeight        = 0.0
local initHeight          = 0.0
local currentHeight       = 0.0
local fallSpeed           = 9.8
local fallSpeedMultiplier = 2.0
local jumpMomentum        = 40.0
local jumpMultiplier      = 6.0
local currentJumpHeight   = 0.0
local timeInAir           = 0.0
local collisionTestMultiplier = 10
local lineEnd = nil
local offset = 2.0
local view = nil
 
local worldUp     = math.vec3:new()
local forwardDir  = math.vec3:new()
local upDir       = math.vec3:new()
local downDir     = math.vec3:new()
local backwardDir = math.vec3:new()
local flatRight   = math.vec3:new()
local flatForward = math.vec3:new()

function start()
    print("test.lua : start")
    worldUp.y = 1.0
    viewEntity = harmony.GetViewEntity(view)
    for x=1,collisionTestMultiplier do
        for y=1,collisionTestMultiplier do
            newEntity = harmony.GetScene():AddEntity()
            newEntity:AddTransform()
            newEntity:AddSphere()
            t = newEntity:GetTransform()
            t.position.x = t.position.x + (x * offset)
            t.position.z = t.position.z + (y * offset)
            s = newEntity:GetSphere()
            s.radius = 2.0
        end
    end
end

function getMovementVector(a)
    deltaTime = time.GetFrameTime();
    dtVec = math.vec3:new()
    dtVec.x = deltaTime * speed * a
    dtVec.y = deltaTime * speed * a
    dtVec.z = deltaTime * speed * a
    return dtVec
end

function GetKeyboardMovement()
    movement = math.vec2:new()
    if input.GetKey(input.key.W) then
        movement.y = -1.0
    end
    if input.GetKey(input.key.S) then
        movement.y = 1.0
    end

    if input.GetKey(input.key.D) then
        movement.x = 1.0
    end

    if input.GetKey(input.key.A) then
        movement.x = -1.0
    end
    return movement
end

function GetMouseLook()
    vel = input.GetMouseVelocity()
    vel.x = vel.x * 75.0
    vel.y = vel.y * 75.0
    return vel
end

function GetControllerMovement()
    return input.GetGamepadStick(0, input.gamePadStick.LS)
end

function GetControllerLook()
    return input.GetGamepadStick(0, input.gamePadStick.RS)
end

function Jump()
    currentJumpHeight = jumpMomentum
    currentHeight = currentHeight + (currentJumpHeight * deltaTime)
    timeInAir = 0.0
end

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

function ray(position, dir)
    lineEnd = math.subVec3(position, dir)    
    hits = collision.raycast(position, dir)
    if hits:size() > 0 then
        lineEnd = hits[1].position
    end
    debug.DrawLine(position,lineEnd)
    debug.SetColour(0.0, 255.0, 0.0, 255.0)
    debug.DrawSphere(lineEnd, 0.125)
    debug.SetColour(255.0, 255.0, 255.0, 255.0)
    return lineEnd
end

function UpdateDirectionVectors(t)
    flatRight   = t.right
    flatForward = t.forward

    forwardDir = math.mulVec3f(t.forward, 10.0)
    upDir = math.mulVec3f(worldUp, 10.0)
    backwardDir = math.mulVec3f(t.forward, -10.0)
    downDir = math.mulVec3f(worldUp, -10.0)
end

function update()
    deltaTime = time.GetFrameTime();
    GetView()
    viewEntity = harmony.GetViewEntity(view)
    t = viewEntity:GetTransform()
    
    UpdateDirectionVectors(t)

    ray(t.position, forwardDir)
    ray(t.position, upDir)
    downHit = ray(t.position, downDir)

    ls = GetControllerMovement()
    rs = GetControllerLook()

    groundHeight = initHeight

    if(downHit.y > groundHeight) then
        groundHeight = downHit.y    
    end

    heightDiff = groundHeight - currentHeight
    if input.GetGamepadButton(0, input.gamePadButton.FaceSouth) and heightDiff >= 0.3 then
        Jump()
    end

    forwardVec = getMovementVector(ls.y)
    rightVec = getMovementVector(ls.x)
        
    if currentHeight > groundHeight then
        timeInAir = timeInAir + deltaTime * fallSpeedMultiplier
        currentJumpHeight = currentJumpHeight - deltaTime * fallSpeed * jumpMultiplier
        currentHeight = currentHeight + (currentJumpHeight * deltaTime)
        if(timeInAir < 1.0) then
            currentHeight = currentHeight - deltaTime * fallSpeed
        else
            currentHeight = currentHeight - deltaTime * fallSpeed * timeInAir
        end
    else
        currentHeight = initHeight
        timeInAir = 0.0
    end

    if currentJumpHeight < 0.0 then
        currentJumpHeight = 0.0
    end

    if math.abs(ls.x) > deadZone or math.abs(ls.y) > deadZone then
        t.position = math.addVec3(t.position, math.mulVec3(flatForward, forwardVec))
        t.position = math.addVec3(t.position, math.mulVec3(flatRight, rightVec))
    end

    t.position.y = currentHeight

    r = deltaTime * rotationBase * rotationMulti;

    if math.abs(rs.x * r) > deadZone or math.abs(rs.y * r) > deadZone then
        t.euler.x = t.euler.x - rs.y * r
        t.euler.y = t.euler.y - rs.x * r
    end
    
    if t.euler.x > limitX then
        t.euler.x = limitX;
    end

    if t.euler.x < lowerLimitX then
        t.euler.x = lowerLimitX
    end
end

function cleanup()
    print("TestLua : Cleanup")
end