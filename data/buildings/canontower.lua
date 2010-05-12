-- DRAFT
-- A canon tower specified through lua script

CanonTower = {}
CanonTower.__index = CanonTower


-- image
CanonTower.sprite = "data/building/canontower.png"
CanonTower.spriteWidth =  16
CanonTower.spriteHeight = 16

-- animations
CanonTower.idleAnimationStart = 1
CanonTower.idleAnimationStop = 1
CanonTower.fireAnimationStart = 2
CanonTower.fireAnimationStop = 6
CanonTower.buildAnimationStart = 7
CanonTower.buildAnimationStop = 7

--properties
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
    -- New CanonTower Instance is already created from source
end


-- Fire Modes: static, following, relational
   -- static: a position where the target was at firing
   -- following: track target position and follow
   -- relational: a position where target is in time

-- Fire Strategy: strongest, weakest, nearest, farthest


--update canon tower
function CanonTower:Update(elapsedTime)
    -- when enough time fire bullet at enemy
    -- bullet set current position from the self position
    -- bullet creates though native class for the right options?
    self.Fire()
    
    --target can be a creature or a position
    -- creature: bullet following automatically the aiming creature
    -- position: bullet fly to position and hit the stuff there
end

--Register Building Type 
Shared.AddBuildingType("CanonTower", CanonTower);

