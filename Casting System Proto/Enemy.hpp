#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
	Enemy();

public:

private:
	int health;
	float movementSpeed;
	sf::Vector2f velocity;
	sf::RectangleShape enemySprite;

};

