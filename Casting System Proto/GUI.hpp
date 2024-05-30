#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"

class GUI
{
private:

	std::string fontsPath = "C:/Users/vampi/source/repos/Casting System Proto/Fonts";

	sf::Text fpsText;
	sf::Font fpsTextFont;
	
	std::vector<sf::CircleShape> fireballGUIElements;

public:

	GUI(Player& player);

	sf::Text& GetFpsText();
	void UpdateFpsText(float framerate);
	void LoadFireballGUI(Player& player);
	void UpdateFireBallGUIPosition(Player& player);
	
	bool hasFireBallInHand = false;

	std::vector<sf::CircleShape> SpellAmmoGUI;

	sf::CircleShape fireballOne;
	sf::CircleShape fireballTwo;
	sf::CircleShape fireballThree;
};

