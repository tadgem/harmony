
e = nil 

function start()
    print("TestLua : Start")
    e = this_entity
    scene = harmony.GetScene()
    scene.AddEntity()
    print(t.position.x)
end

function update()
    -- print("TestLua : Update")
end

function cleanup()
    print("TestLua : Cleanup")
end