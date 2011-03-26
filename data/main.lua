-------------------------------------------------------------------------------
-- General Game Start Script
-- License GPLv2
-------------------------------------------------------------------------------

-- Lib

function new( baseTable)
    local new_table = { __index= baseTable }
    setmetatable( new_table, baseTable)

    --todo look if OnCreate exist call it

    return new_table
end

-- Lua has no constants by default. Using metatables
-- we can save the state of a table and forbid any
-- changes to it. This function does that exactly
function makereadonly(t)
    -- the metatable
    local mt = { __index = t,
                 __newindex = function(t, k, v)
                     error("trying to modify constant field " .. tostring(k), 2)
                 end
    }
    return setmetatable({}, mt)
end

print("Startup Game main.lua")

-- Load Base Table/Classes
-- Shared.LoadScript("data/bullets/bullet.lua");
-- Shared.LoadScript("data/research/research.lua");
-- Shared.LoadScript("data/buildings/building.lua");
-- Shared.LoadScript("data/creatures/creature.lua");


-- Bullets
-- Shared.LoadScript("data/bullets/canonball.lua");

-- Researchs
-- Shared.LoadScript("data/research/KillBonus.lua");

-- Creatures
-- Shared.LoadScript("data/creatures/roach.lua");

-- Buildings
-- Shared.LoadScript("data/buildings/canontower.lua");
-- Shared.LoadScript("data/buildings/factory.lua");