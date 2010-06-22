-- DRAFT
-- A canon tower specified through lua script
-- License GPLv2

Factory = {}

-- primer
Factory.name = "Factory"
Factory.type = "Building"
Factory.description = "Producing xxx"

function Factory:OnCreate()

end

-- Register
Shared.RegisterGameObject(Factory, "Factory")