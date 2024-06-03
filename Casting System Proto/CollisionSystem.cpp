#include "CollisionSystem.hpp"

void CollisionSystem::CheckForOverlaps(std::vector<FireballSpellGraphic>& fireballs,
	std::vector<IcewallSpellGraphic>& icewalls,
	sf::RectangleShape& enemyTarget)
{
	for (size_t i = 0; i < fireballs.size(); i++)
	{
		if (fireballs[i].fireballGraphics().getGlobalBounds().intersects(enemyTarget.getGlobalBounds()))
		{
			fireballs[i].MarkForDeletion();
			//enemyTarget.TakeDamage(fireballs[i].GetSpellDamage();
		}

	}
}
