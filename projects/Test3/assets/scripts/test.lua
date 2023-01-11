
e = nil 

function start()
    print("TestLua : Start")
    e = harmony.GetEntity()
end

function update()
    -- print("TestLua : Update")
    t = e:GetTransform()
    t.position.y = t.position.y - 0.002;
    e:SetTransform(t)
end

function cleanup()
    print("TestLua : Cleanup")
end