-- DRAFT
-- A canonball bullet fired by a canontower
-- License GPLv2

CanonBall = {}

CanonBall.type = "Bullet"
CanonBall.name = "Canon Ball"

CanonBall.description = "A canon ball fired by canon tower"



function CanonBall:Update(elapsedTime)
    -- movement with current speed

end


Shared.RegisterGameObject(CanonBall, "CanonBall")