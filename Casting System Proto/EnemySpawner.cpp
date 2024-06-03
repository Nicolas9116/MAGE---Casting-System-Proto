#include "EnemySpawner.hpp"



void EnemySpawner::SpawnEnemies()
{
	if (enemySpawnClock.getElapsedTime().asSeconds() > spawnFrequencyVariable && enemies.size() < maxEnemies)
	{
		enemySpawnClock.restart();
		enemies.emplace_back();
	}

}

void EnemySpawner::UpdatePosition(Player& player)
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		
	}

}
