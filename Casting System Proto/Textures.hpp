#pragma once
#include <SFML/Graphics.hpp>

class Textures
{

public:	
	Textures();

	void LoadBackgroundTextures();
	void SetupPlayerTex();
	const sf::Texture& GetPlayerTexture() const;
	const sf::Texture& loadRandomBackgroundTexture() const;

private:
	sf::Texture backgroundTex;
	std::vector <sf::Texture> backgroundTextures;
	std::string texturePath = "C:/Users/vampi/source/repos/Casting System Proto/Sprites";
	sf::Texture playerTex;
	
};
