#pragma once
#include "SpellGraphics.hpp"

class CollisionSystem
{
private:


public:

	void CheckForOverlaps(std::vector<FireballSpellGraphic>& fireballs,
		std::vector<IcewallSpellGraphic>& icewalls,
		sf::RectangleShape& enemyTarget);

	void ResolveOverlaps();
};

