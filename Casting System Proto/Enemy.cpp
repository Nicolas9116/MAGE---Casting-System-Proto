#include "Enemy.hpp"

Enemy::Enemy(sf::Texture& enemyTex) : movementSpeed(30), health(30), velocity(0, 0)
{
	enemySprite.setTexture(enemyTex);
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	enemySprite.setPosition(0, 0);
	enemySprite.setScale(3, 3);
}


sf::Sprite& Enemy::GetSprite()
{
    return enemySprite;
}

float& Enemy::GetMovementSpeed()
{
    return movementSpeed;
}

bool Enemy::ShouldBeDeleted() const
{
	return shouldBeDeleted;
}

void Enemy::TakeDamage(int damage)
{
	health -= damage;	
}

int& Enemy::GetHealth()
{
	return health;
}

sf::Vector2f& Enemy::GetVelocity()
{
	return velocity;
}

void Enemy::UpdateVelocity(sf::Vector2f newVelocity)
{
		velocity += newVelocity;	
}

void Enemy::ResetVelocity()
{
	velocity = sf::Vector2f(0,0);
}

void Enemy::MarkForDeletion()
{
	shouldBeDeleted = true;
}
