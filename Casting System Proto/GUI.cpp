#include "GUI.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>


GUI::GUI(Player& player)
{
	fpsTextFont.loadFromFile(fontsPath + "/fps_font.ttf");
	fpsText.setFont(fpsTextFont);
	fpsText.setString("FPS: ");
	fpsText.setScale(1, 1);
	fpsText.setOrigin(fpsText.getGlobalBounds().width / 2, fpsText.getGlobalBounds().height / 2);
	fpsText.setPosition(1750, 10);
	fpsText.setFillColor(sf::Color::Yellow);

	LoadFireballGUI(player);
}

sf::Text& GUI::GetFpsText()
{
	return fpsText;
}

void GUI::UpdateFpsText(float framerate)
{
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(2) << framerate;
	fpsText.setString("FPS " + stream.str());
}

void GUI::LoadFireballGUI(Player& player)
{
	int fireballGuiOffsetY = 30;

	fireballOne.setRadius(10);
	fireballOne.setPointCount(10);
	fireballOne.setFillColor(sf::Color::Yellow);
	fireballOne.setOutlineColor(sf::Color::Red);
	fireballOne.setScale(1, 1);
	fireballOne.setOrigin(fireballOne.getGlobalBounds().width / 2, fireballOne.getGlobalBounds().height / 2);
	fireballOne.setPosition(player.GetSprite().getPosition().x + 50, player.GetSprite().getPosition().y - 10);

	fireballTwo.setRadius(10);
	fireballTwo.setPointCount(10);
	fireballTwo.setFillColor(sf::Color::Yellow);
	fireballTwo.setOutlineColor(sf::Color::Red);
	fireballTwo.setScale(1, 1);
	fireballTwo.setOrigin(fireballTwo.getGlobalBounds().width / 2, fireballTwo.getGlobalBounds().height / 2);
	fireballTwo.setPosition(player.GetSprite().getPosition().x + 50, player.GetSprite().getPosition().y + fireballGuiOffsetY - 10);

	fireballThree.setRadius(10);
	fireballThree.setPointCount(10);
	fireballThree.setFillColor(sf::Color::Yellow);
	fireballThree.setOutlineColor(sf::Color::Red);
	fireballThree.setScale(1, 1);
	fireballThree.setOrigin(fireballThree.getGlobalBounds().width / 2, fireballThree.getGlobalBounds().height / 2);
	fireballThree.setPosition(player.GetSprite().getPosition().x + 50, player.GetSprite().getPosition().y + fireballGuiOffsetY * 2 - 10);

	std::cout << "x : " + std::to_string(fireballThree.getPosition().x) << " y: " + std::to_string(fireballThree.getPosition().y) << std::endl;

	SpellAmmoGUI.push_back(fireballOne);
	SpellAmmoGUI.push_back(fireballTwo);
	SpellAmmoGUI.push_back(fireballThree);
}

void GUI::UpdateFireBallGUIPosition(Player& player)
{
	int fireballGuiOffsetY = 30;

	SpellAmmoGUI[0].setPosition(player.GetSprite().getPosition().x + 50, player.GetSprite().getPosition().y - 10);
	SpellAmmoGUI[1].setPosition(player.GetSprite().getPosition().x + 50, player.GetSprite().getPosition().y + fireballGuiOffsetY - 10);
	SpellAmmoGUI[2].setPosition(player.GetSprite().getPosition().x + 50, player.GetSprite().getPosition().y + fireballGuiOffsetY * 2 - 10);
}


