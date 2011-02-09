-- DRAFT
-- A canonball bullet fired by a canontower
-- License GPLv2

CanonBall = new(Bullet)

-- primary properties
CanonBall.type = "Bullet"
CanonBall.name = "CanonBall"
CanonBall.description = "A canon ball fired by canon tower"

-- bullet properties
CanonBall.speed = 5
CanonBall.level = 0

-- constructor
function CanonBall:OnCreate()
    --self.pos = {x=0, y=0, z=0}

    -- self.model = Shared.GetModel(1);
    --self.model = Shared.GetModel("bla")
end


-- update position?
function CanonBall:Update(elapsedTime)
    -- movement with current speed into target direction
    
    -- hits target?

    -- do damage?
    -- creates particle effect?
end

function CanonBall:setTarget(target)
    -- target table requieres y,x,z variables
    self.target = target
end

-- set level
function CanonBall:setLevel(level)

end


Shared.RegisterGameObject(CanonBall, "CanonBall")