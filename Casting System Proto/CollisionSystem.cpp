#include "CollisionSystem.hpp"
#include <vector>	
#include "Enemy.hpp"
#include <iostream>
#include "Player.hpp"

void CollisionSystem::CheckForOverlaps(std::vector<FireballSpellGraphic>& fireballs,
	std::vector<IcewallSpellGraphic>& icewalls,
	std::vector<Enemy>& enemies, Player& player)
{
	for (size_t i = 0; i < fireballs.size(); i++)
	{
		for (size_t j = 0; j < enemies.size(); j++)
		{
			if (fireballs[i].fireballGraphics().getGlobalBounds().intersects(enemies[j].GetSprite().getGlobalBounds()))
			{
				fireballs[i].MarkForDeletion();
				enemies[j].TakeDamage(fireballs[i].GetSpellDamage());
				if (enemies[j].GetHealth() <= 0)
				{
				enemies[j].MarkForDeletion();	
				}
				std::cout << "Enemy hit by fireball" << "health is " << enemies[j].GetHealth() << std::endl;
			}
		}
	}

	//for the icewalls, the enemies dont' take damage, they just get pushed away in the direction they were moving a little bit
	for (size_t i = 0; i < icewalls.size(); i++)
	{
		for (size_t j = 0; j < enemies.size(); j++)
		{
			if (icewalls[i].icewallGraphics().getGlobalBounds().intersects(enemies[j].GetSprite().getGlobalBounds()))
			{
				enemies[j].GetSprite().move(enemies[j].GetVelocity() * -1.0f);
				std::cout << "Enemy hit by icewall " << std::to_string(enemies[j].GetSprite().getPosition().x) << " , "<< std::to_string(enemies[j].GetSprite().getPosition().y) << std::endl;
			}
		}
	}

	//check for overlaps between enemies and the player
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].GetSprite().getGlobalBounds().intersects(player.GetSprite().getGlobalBounds()))
		{
			player.TakeDamage(1);
			enemies[i].MarkForDeletion();
		}
	}

	//check for overlap between enemies and other enemies, added logic for moving enemies out of each other
	for (size_t i = 0; i < enemies.size(); i++)
	{
		for (size_t j = 0; j < enemies.size(); j++)
		{
			if (i != j)
			{
				sf::FloatRect intersectBox;

				if (enemies[i].GetSprite().getGlobalBounds().intersects(enemies[j].GetSprite().getGlobalBounds(),intersectBox))
				{
					//reset velocity of enemies in collision
					enemies[i].ResetVelocity();
					enemies[j].ResetVelocity();

					sf::Vector2f intersectBoxSize = intersectBox.getSize();
					
					enemies[i].GetSprite().move(-(intersectBoxSize.x / 2), -(intersectBoxSize.y / 2));
					enemies[j].GetSprite().move((intersectBoxSize.x / 2), (intersectBoxSize.y / 2));
				}
			}
		}
	}
}					
