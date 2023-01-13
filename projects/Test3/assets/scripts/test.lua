
e = nil 
speed = 0.33
rotationBase = 180.0
rotationMulti = 1.0;
rotationThreshold = 0.0

limitX = 60
lowerLimitX = 0.0 - limitX

function start()
    print("TestLua : Start")
    e = harmony.GetEntity()
end

function getMovementVector(a)
    deltaTime = time.GetFrameTime();
    dtVec = math.vec3:new()
    dtVec.x = deltaTime * speed * a
    dtVec.y = deltaTime * speed * a
    dtVec.z = deltaTime * speed * a
    return dtVec
end

function update()
    deltaTime = time.GetFrameTime();
    view = harmony.GetView("RuntimeView")
    viewEntity = harmony.GetViewEntity(view)
    t = viewEntity:GetTransform()
    
    flatRight   = t.right
    flatForward = t.forward

    flatRight.y     = 0.0
    flatForward.y   = 0.0

    ls = input.GetGamepadStick(0, input.gamePadStick.LS)
    rs = input.GetGamepadStick(0, input.gamePadStick.RS)

    forwardVec = getMovementVector(ls.y)
    rightVec = getMovementVector(ls.x)

    t.position = math.addVec3(t.position, math.mulVec3(flatForward, forwardVec))
    t.position = math.addVec3(t.position, math.mulVec3(flatRight, rightVec))
    
    r = deltaTime * rotationBase * rotationMulti;

    t.euler.x = t.euler.x - rs.y * r
    t.euler.y = t.euler.y - rs.x * r
    
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