
e                   = nil 
speed               = 4.0
rotationBase        = 180.0
rotationMulti       = 1.0;
rotationThreshold   = 0.0
deadZone            = 0.1
limitX              = 60
lowerLimitX         = 0.0 - limitX

initHeight          = 0.0
currentHeight       = 0.0
fallSpeed           = 9.8
fallSpeedMultiplier = 2.0
jumpMomentum        = 55.0
jumpMultiplier      = 6.0
currentJumpHeight   = 0.0
timeInAir = 0.0

lineEnd = nil

function start()
    print("test.lua : start")
    viewEntity = harmony.GetViewEntity(view)
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
    vel.x = vel.x * 25.0
    vel.y = vel.y * 25.0
    return vel
end

function GetControllerMovement()
    return input.GetGamepadStick(0, input.gamePadStick.LS)
end

function GetControllerLook()
    input.GetGamepadStick(0, input.gamePadStick.RS)
end

function jump()
    currentJumpHeight = jumpMomentum
    currentHeight = currentHeight + (currentJumpHeight * deltaTime)
    timeInAir = 0.0
end

function update()
    deltaTime = time.GetFrameTime();
    view = harmony.GetView("RuntimeView")
    viewEntity = harmony.GetViewEntity(view)
    t = viewEntity:GetTransform()
    
    flatRight   = t.right
    flatForward = t.forward
    dir = math.mulVec3f(t.forward, 10.0)
    lineEnd = math.subVec3(t.position, dir)    
    hits = collision.raycast(t.position, dir)
    if hits:size() > 0 then
        lineEnd = hits[1].position
    end
    debug.DrawLine(t.position,lineEnd)
    debug.SetColour(0.0, 255.0, 0.0, 255.0)
    debug.DrawSphere(lineEnd, 0.25)
    
    flatRight.y     = 0.0
    flatForward.y   = 0.0

    ls = GetKeyboardMovement()
    rs = GetMouseLook()

    if input.GetGamepadButton(0, input.gamePadButton.FaceSouth) and currentHeight <= initHeight then
        print("Jump")
        jump()
    end

    forwardVec = getMovementVector(ls.y)
    rightVec = getMovementVector(ls.x)
    
    
    if currentHeight > initHeight then
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
    viewEntity:SetTransform(t)
end

function cleanup()
    print("TestLua : Cleanup")
end