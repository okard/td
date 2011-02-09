-- DRAFT
-- A research
-- License GPLv2

KillBonusResearch = new(Research)

-- primer
KillBonusResearch.type = "Research"
KillBonusResearch.name = "Kill Bonus"
KillBonusResearch.decription = "Get extra money when killing an enemy"

-- special research option this cant be instantiated
KillBonusResearch.global = true

--instance stuff
KillBonusResearch.isResearched = false
KillBonusResearch.researchTime = 60000 -- one minute
KillBonusResearch.isResearching = false
KillBonusResearch.timeLeft = 0


function KillBonusResearch:Research()
    -- check player for money

    -- start research
    if not self.isResearched then
        self.isResearching = true
        self.timeLeft = self.researchTime
    end
end

function KillBonusResearch:OnUpdate()
    
    if self.isResearching then
       -- time left - elapsed time 
       -- if time left <= 0 then is researched
    end
end

-- Register
Shared.RegisterGameObject(KillBonusResearch, "KillBonusResearch")

