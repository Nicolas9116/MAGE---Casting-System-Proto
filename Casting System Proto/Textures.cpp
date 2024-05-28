#include "Textures.hpp"
#include <iostream>

Textures::Textures() : texturePath("C:/Users/vampi/source/repos/Casting System Proto/Sprites")
{
	SetupPlayerTex();
}

void Textures::SetupPlayerTex()
{
	if (!playerTex.loadFromFile(texturePath + "/player_sprite.png"))
	{
		std::cout << "Unable to load player sprite" << std::endl;
	}

}

const sf::Texture& Textures::GetPlayerTexture() const
{
	return playerTex;
}
