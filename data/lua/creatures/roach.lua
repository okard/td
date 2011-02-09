-- DRAFT
-- Roach creature
-- License GPLv2

Roach = {}

Roach.type = "Creature"
Roach.name = "Roach"
Roach.description = "A sample creature"


function Roach:OnCreate()
    self.hp = 100
end

function Roach:OnDestroy()
    -- kill scene node, model
end


function Roach:OnUpdate()
    -- move
    -- decision where to move
end

-- gets damage from a bullet,...
function Roach:GetDamage(dmg)
    
    self.hp = self.hp - dmg

    --destroyed
    if(self.hp <= 0)
        self:OnDestroy()
end

Shared.RegisterGameObject(Roach, "Roach")