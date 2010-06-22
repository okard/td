-- DRAFT
-- A canon tower specified through lua script
-- License GPLv2

CanonTower = new(Building)

-- Game Object Basic
CanonTower.name = "CanonTower"
CanonTower.type = "Building"
CanonTower.description = "A canon tower fires canon balls"


-- image
CanonTower.sprite = "data/buildings/canontower.png"
CanonTower.spriteWidth =  50
CanonTower.spriteHeight = 48
CanonTower.icon = "data/buildings/canontower_icon.png"
CanonTower.mesh = ""

-- animations
CanonTower.idle = "Idle"
CanonTower.shoot = "Shoot"

--properties logic
CanonTower.prefix = "ct"
CanonTower.cost = 200
CanonTower.range = 10
CanonTower.bullet = "canonball"
CanonTower.bulletLevel = 5
CanonTower.speed = 3                -- fire rate seconds
CanonTower.buildTime = 20           -- 20 seconds to build     
CanonTower.level = 1                -- start level
CanonTower.dependency = nil         -- depends not on research

-- Event Called after object creation
function CanonTower:OnCreate()
    print("On Create Called")
    -- New CanonTower Instance is already created from source
    self.elapsedTime = 0
end


-- Fire Modes: static, following, relational
   -- static: a position where the target was at firing
   -- following: track target position and follow
   -- relational: a position where target is in time

-- Fire Strategy: strongest, weakest, nearest, farthest

--update canon tower
function CanonTower:Update(elapsedTime)
    --for k,v in pairs(getmetatable(newBuilding_1)) do print(k,v) end
    --print(self)


    self.elapsedTime = self.elapsedTime + elapsedTime

    if self.elapsedTime > 10000 then
        self:Fire()
    --    print(elapsedTime)
        --print(self.name)
        self.elapsedTime = 0
    end
    --Bullet = new Bullet();
    --Shared.AddGameObject(Bullet);
    --local bullet = Shared.Spawn(self.bullet);
    --local bullet = Shared.Spawn(CanonBall); 
    -- use directly the table as parameter

    --target can be a creature or a position
    -- creature: bullet following automatically the aiming creature
    -- position: bullet fly to position and hit the stuff there
end

--Register CanonTower String must be identical to variable 
Shared.RegisterGameObject(CanonTower, "CanonTower")

