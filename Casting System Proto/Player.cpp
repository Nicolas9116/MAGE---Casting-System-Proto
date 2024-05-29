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
	//std::cout << "CASTING" << std::endl;
}

void Player::SetIsCastingFalse()
{
	isCasting = false;
	//std::cout << "NOT CASTING" << std::endl;
}

sf::Sprite& Player::GetSprite()
{
	return playerSprite;
}

float Player::GetMovementSpeed() const
{
	return movementSpeed;
}

Spellbook& Player::GetSpellBook()
{
	return playerSpellbook;
}

void Player::SetSpellInHand(bool isSpellInHand)
{
	spellInHand = isSpellInHand;
}

const bool Player::IsSpellInHand() const
{
	return spellInHand;
}
