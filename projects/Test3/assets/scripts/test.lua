
e = nil 

function start()
    print("TestLua : Start")
    e = harmony.GetEntity()
end

function update()
    -- print("TestLua : Update")
    ent = harmony.GetEntity()
    v = ent.GetPosition()
    v.y = v.y + 0.03;
    ent.SetPosition(v)
end

function cleanup()
    print("TestLua : Cleanup")
end