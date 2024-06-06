#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{


public:

	Enemy(sf::Texture& enemyTex);
	sf::Sprite& GetSprite();
	float& GetMovementSpeed();
	bool ShouldBeDeleted() const;
	void TakeDamage(int damage);
	int& GetHealth();
	sf::Vector2f& GetVelocity();
	void UpdateVelocity(sf::Vector2f newVelocity);	
	void ResetVelocity();
	void MarkForDeletion();
private:
	int health;
	float movementSpeed;
	sf::Vector2f velocity;
	sf::Sprite enemySprite;
	bool shouldBeDeleted = false;
};

