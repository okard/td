-- DRAFT
-- A canon tower specified through lua script

CanonTower = {}


-- image
CanonTower.sprite = "data/buildings/canontower.png"
CanonTower.spriteWidth =  50
CanonTower.spriteHeight = 48
CanonTower.icon = "data/buildings/canontower_icon.png"

-- animations
CanonTower.idleAnimationStart = 1
CanonTower.idleAnimationStop = 1
CanonTower.fireAnimationStart = 2
CanonTower.fireAnimationStop = 6
CanonTower.buildAnimationStart = 7
CanonTower.buildAnimationStop = 7

--properties
CanonTower.name = "CanonTower"
CanonTower.category = "building"
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

    self:Fire()
    print(elapsedTime)
    print(self.name)

    --Bullet = new Bullet();
    --Shared.AddGameObject(Bullet);

    --target can be a creature or a position
    -- creature: bullet following automatically the aiming creature
    -- position: bullet fly to position and hit the stuff there
end

--Register CanonTower String must be identical to variable 
Shared.AddBuildingType("CanonTower");

