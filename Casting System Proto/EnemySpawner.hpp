#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Player.hpp"

class EnemySpawner
{
public:
	void SpawnEnemies();
	void UpdatePosition(Player& player, sf::Time frameTime);
	std::vector<Enemy>& GetEnemies();

private:
	sf::Clock enemySpawnClock;
	std::vector<Enemy> enemies;
	int spawnFrequencyVariable = 5;
	int maxEnemies = 10;
};

