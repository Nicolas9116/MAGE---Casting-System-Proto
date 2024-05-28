#include "Player.hpp"
#include <iostream>

Player::Player(const sf::Texture& playerTex)
	: playerTexture(playerTex), isCasting(false), movementSpeed(200.0f)
{
	playerSprite.setTexture(playerTex, true);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
	playerSprite.setScale(.1f, .1f);
	playerSprite.setPosition(960, 540);
}

void Player::Update(int& direction)
{
	fireball.UpdateCombo(direction);

	if (fireball.isComboComplete())
	{
		std::cout << "FIREBALL" << std::endl;
		fireballInHand = true;
		fireballsInHand = maxFireballs;
		fireball.ResetComboState();
	}
}


void Player::draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}

bool Player::IsCasting() const
{
	return isCasting;
}

void Player::SetIsCastingTrue()
{
	isCasting = true;
	std::cout << "CASTING" << std::endl;
}

void Player::SetIsCastingFalse()
{
	isCasting = false;
	std::cout << "NOT CASTING" << std::endl;
}

sf::Sprite& Player::GetSprite()
{
	return playerSprite;
}

float Player::GetMovementSpeed() const
{
	return movementSpeed;
}

bool Player::IsFireBallInHand()
{
	return fireballInHand;
}

void Player::CastFireBall(sf::Vector2i& fireballTarget)
{
	if (fireballsInHand > 0)
	{
		fireballsInHand--;

		Fireball fireball;
		fireball.shape.setRadius(10);
		fireball.shape.setPointCount(10);
		fireball.shape.setFillColor(sf::Color::Yellow);
		fireball.shape.setOutlineColor(sf::Color::Red);
		fireball.shape.setScale(3, 3);
		fireball.shape.setOrigin(fireball.shape.getGlobalBounds().width / 2, fireball.shape.getGlobalBounds().height / 2);
		fireball.shape.setPosition(static_cast<float>(fireballTarget.x), static_cast<float>(fireballTarget.y));
		fireball.lifespan = 3.0f; // Set fireball lifespan to 3 seconds

		activeFireballs.push_back(fireball);
	}
}

void Player::UpdateFireballs(float deltaTime)
{
	// Update fireball lifespans and remove expired fireballs
	for (auto it = activeFireballs.begin(); it != activeFireballs.end();)
	{
		it->lifespan -= deltaTime;
		if (it->lifespan <= 0)
		{
			it = activeFireballs.erase(it); // Remove expired fireball
		}
		else
		{
			++it;
		}
	}
}

std::vector<Fireball>& Player::GetActiveFireballs()
{
	return activeFireballs;
}
