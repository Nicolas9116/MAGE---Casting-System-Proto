#include "Textures.hpp"
#include <iostream>

Textures::Textures() : texturePath("C:/Users/vampi/source/repos/Casting System Proto/Sprites")
{
	SetupPlayerTex();
	LoadBackgroundTextures();
}

void Textures::LoadBackgroundTextures()
{
	for (int i = 1; i < 18; i++)
	{
		backgroundTex.loadFromFile(texturePath + "/Background/Tile_" + std::to_string(i) + ".png");
		backgroundTextures.push_back(backgroundTex);
		std::cout << "Loaded background texture " << i << std::endl;
		std::cout << backgroundTextures.size() << std::endl;
	}
	
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

const sf::Texture& Textures::loadRandomBackgroundTexture() const
{
	{
		return backgroundTextures[rand() % backgroundTextures.size()];
	}
}
