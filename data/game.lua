-------------------------------------------------------------------------------
-- General Game Script
-- License GPLv2
-------------------------------------------------------------------------------

-- Lib

function new( baseTable)
    local new_table = { __index= baseTable }
    setmetatable( new_table, baseTable)

    return new_table
end

-- Load Base Table/Classes
Shared.LoadScript("data/bullets/bullet.lua");
Shared.LoadScript("data/research/research.lua");
Shared.LoadScript("data/buildings/building.lua");
Shared.LoadScript("data/creatures/creature.lua");


-- Bullets
Shared.LoadScript("data/bullets/canonball.lua");

-- Researchs
Shared.LoadScript("data/research/KillBonus.lua");

-- Creatures
Shared.LoadScript("data/creatures/roach.lua");

-- Buildings
Shared.LoadScript("data/buildings/canontower.lua");
Shared.LoadScript("data/buildings/factory.lua");