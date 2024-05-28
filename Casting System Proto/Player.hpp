#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.hpp"

class Player
{
private:

	sf::Sprite playerSprite;
	const sf::Texture& playerTexture;
public:

	Player(const sf::Texture& playerTex);
	const sf::Sprite& GetSprite();
};

