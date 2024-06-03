#include "Enemy.hpp"

Enemy::Enemy()
{
	int health = 30;
	float movementSpeed = 1;
	enemySprite.setSize(sf::Vector2f(50, 50));
	enemySprite.setFillColor(sf::Color::Green);
	enemySprite.setOutlineColor(sf::Color::White);
	enemySprite.setOutlineThickness(1);
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	enemySprite.setPosition(0, 0);
}
