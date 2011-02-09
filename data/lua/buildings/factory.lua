-- DRAFT
-- A canon tower specified through lua script
-- License GPLv2

Factory = new(Building)

-- primer
Factory.name = "Factory"
Factory.type = "Building"
Factory.description = "Producing xxx"

-- researchs which can be researched at this building (global research here)
-- not global researches can be added with new(ResearchName)
Factory.researchs = {KillBonusResearch}


-- Constructor of a new factory
function Factory:OnCreate()

end

-- Register
Shared.RegisterGameObject(Factory, "Factory")