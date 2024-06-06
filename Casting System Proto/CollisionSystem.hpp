#pragma once
#include <vector>	
#include "SpellGraphics.hpp"

class Enemy;

class CollisionSystem
{
private:


public:

	void CheckForOverlaps(std::vector<FireballSpellGraphic>& fireballs,
		std::vector<IcewallSpellGraphic>& icewalls,
		std::vector<Enemy>& enemies,
		Player& player);
};

