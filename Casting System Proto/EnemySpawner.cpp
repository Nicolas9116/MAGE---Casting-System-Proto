																																																																																																	#include "EnemySpawner.hpp"

void EnemySpawner::SpawnEnemies()
{
	if (enemySpawnClock.getElapsedTime().asSeconds() > spawnFrequencyVariable && enemies.size() < maxEnemies)
	{
		enemySpawnClock.restart();
		enemies.emplace_back();
	}

}

void EnemySpawner::UpdatePosition(Player& player, sf::Time frameTime)
{
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
	[](const Enemy& enemy) { return enemy.ShouldBeDeleted(); }), enemies.end());

	sf::Vector2f playerPos = player.GetSprite().getPosition();

	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].ResetVelocity();
		sf::Vector2f enemyPos = enemies[i].GetSprite().getPosition();
		sf::Vector2f enemyMovement = playerPos - enemyPos;
		//need to normalise the enemyMovement vector
		float enemyMovementMagnitude = std::sqrt(enemyMovement.x * enemyMovement.x + enemyMovement.y * enemyMovement.y);
		sf::Vector2f normalizedEnemyMovement = enemyMovement / enemyMovementMagnitude;

		// Update the position of the enemy
		sf::Vector2f EnemyMovementThisFrame = (normalizedEnemyMovement * enemies[i].GetMovementSpeed()) * frameTime.asSeconds();
		enemies[i].UpdateVelocity(EnemyMovementThisFrame);
		enemies[i].GetSprite().move(enemies[i].GetVelocity());
	}

}

std::vector<Enemy>& EnemySpawner::GetEnemies()
{
	return enemies;
}