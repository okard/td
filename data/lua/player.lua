-------------------------------------------------------------------------------
-- Player
-- License GPLv2
-------------------------------------------------------------------------------

Player = {}


-- Event Called when a Player Object get created
function Player:OnCreate()
    self.Health = 100
    self.Money = 1000
    self.Energy = 1000

end