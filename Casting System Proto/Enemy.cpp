#include "Enemy.hpp"

Enemy::Enemy() : movementSpeed(30), health(30), velocity(0, 0), enemySprite(sf::Vector2f(50, 50))
{
	enemySprite.setFillColor(sf::Color::Green);
	enemySprite.setOutlineColor(sf::Color::White);
	enemySprite.setOutlineThickness(1);
	enemySprite.setOrigin(enemySprite.getSize().x / 2, enemySprite.getSize().y / 2);
	enemySprite.setPosition(0, 0);
}


sf::RectangleShape& Enemy::GetSprite()
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
