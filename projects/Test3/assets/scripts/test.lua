
e = nil 
speed = 0.15
rotationBase = 180.0
rotationMulti = 100.0;
rotationThreshold = 0.002

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
    
    pos = getMovementVector(1.0)
    neg = getMovementVector(-1.0)

    m = input.GetMouseVelocity()

    flatRight   = t.right
    flatForward = t.forward

    flatRight.y     = 0.0
    flatForward.y   = 0.0

    if input.GetKey(input.key.W) then
        t.position = math.addVec3(t.position, math.mulVec3(flatForward, neg))
    end
    if input.GetKey(input.key.S) then
        t.position = math.addVec3(t.position, math.mulVec3(flatForward, pos))
    end

    if input.GetKey(input.key.D) then
        t.position = math.addVec3(t.position, math.mulVec3(flatRight, pos))
    end

    if input.GetKey(input.key.A) then
        t.position = math.addVec3(t.position, math.mulVec3(flatRight, neg))
    end

    mx = math.abs(m.x)
    my = math.abs(m.y)

    if my > rotationThreshold or mx > rotationThreshold  then
        r = deltaTime * rotationBase * rotationMulti;
        t.euler.x = t.euler.x - m.y * r
        t.euler.y = t.euler.y - m.x * r
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