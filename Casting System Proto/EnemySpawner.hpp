#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Player;

class EnemySpawner
{
public:
	void SpawnEnemies();
	void UpdatePosition(Player& player);

private:
	sf::Clock enemySpawnClock;
	std::vector<Enemy> enemies;
	int spawnFrequencyVariable;
	int maxEnemies = 10;
};

