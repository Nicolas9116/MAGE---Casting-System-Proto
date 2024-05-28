#pragma once
#include <SFML/Graphics.hpp>

class Textures
{
	

private:

	std::string texturePath = "C:/Users/vampi/source/repos/Casting System Proto/Sprites";
	sf::Texture playerTex;


public:	
	Textures();

	void SetupPlayerTex();
	const sf::Texture& GetPlayerTexture() const;
};

