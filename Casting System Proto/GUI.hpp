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
	void LoadFireBallGUI(Player& player);
	void UpdateFireBallGUIPosition(Player& player);
	
	bool hasFireBallInHand = false;

	sf::CircleShape fireballOne;
	sf::CircleShape fireballTwo;
	sf::CircleShape fireballThree;
};

