#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "Textures.hpp"

Player::Player(const sf::Texture& playerTex) : playerTexture(playerTex)
{
    playerSprite.setTexture(playerTex, true);
    playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
    playerSprite.setScale(.1f, .1f);
    playerSprite.setPosition(960, 540);
}

const sf::Sprite& Player::GetSprite()
{
    return playerSprite;
}
