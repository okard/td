-- DRAFT
-- A canon tower specified through lua script
-- License GPLv2

Factory = new(Building)

-- primer
Factory.name = "Factory"
Factory.type = "Building"
Factory.description = "Producing xxx"

-- Constructor of a new factory
function Factory:OnCreate()

end

-- Register
Shared.RegisterGameObject(Factory, "Factory")