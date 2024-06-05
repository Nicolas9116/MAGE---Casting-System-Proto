#include "SpellCombo.hpp"
#include <iostream>	

SpellCombo::SpellCombo(const std::vector<int>& combo, const std::string spellName, sf::Sprite& upLit, sf::Sprite& upUnlit,
	sf::Sprite& downLit, sf::Sprite& downUnlit, sf::Sprite& rightLit, sf::Sprite& rightUnlit, sf::Sprite& leftLit, sf::Sprite& leftUnlit)
	: upLit(upLit), upUnlit(upUnlit), downLit(downLit), downUnlit(downUnlit), rightLit(rightLit), rightUnlit(rightUnlit), leftLit(leftLit), leftUnlit(leftUnlit)
{
	correctCombo = combo;
	this->spellName = spellName;

	for (size_t i = 0; i < correctCombo.size(); i++)
	{
		if (correctCombo[i] == 1)
		{
			comboLights.push_back(ComboLight(upLit, upUnlit));
			std::cout << "Up added "<< std::endl;
		}
		else if (correctCombo[i] == 2)
		{
			comboLights.push_back(ComboLight(downLit, downUnlit));
			std::cout << "Down added " << std::endl;
		}
		else if (correctCombo[i] == 4)
		{
			comboLights.push_back(ComboLight(rightLit, rightUnlit));
			std::cout << "Right added " << std::endl;
		}
		else if (correctCombo[i] == 3)
		{
			comboLights.push_back(ComboLight(leftLit, leftUnlit));
			std::cout << "Left added " << std::endl;
		}
	}
	for (size_t i = 0; i < comboLights.size(); i++)
	{
		comboLights[i].SetPosition(sf::Vector2f(100 + (i * comboLights[i].GetLightOffset()), 100 + yOffset));
	}
	yOffset += 100;
}

void SpellCombo::CheckCurrentComboCompletion(std::vector<int> currentInputCombo)
{
	// Get the size of the smallest vector
	size_t size = std::min(currentInputCombo.size(), correctCombo.size());

	for (size_t i = 0; i < size; i++)
	{
		if (currentInputCombo[i] == correctCombo[i])
		{
			// If the current input matches the correct combo, turn on the light
			comboLights[i].LightOn();

			// If the light is not the first one and the previous light is off, turn off the current light
			if (i > 0 && !comboLights[i - 1].GetIsLit())
			{
				comboLights[i].LightOff();
			}
		}
		else
		{
			// If the current input does not match the correct combo, turn off the light
			comboLights[i].LightOff();
		}
	}
}

void SpellCombo::DrawComboLights(sf::RenderWindow& window)
{
	for (int i = 0; i < comboLights.size(); i++)
	{
		window.draw(comboLights[i].GetCurrentLight());
		std::cout<< "Drawing light " << i << "at position" << std::to_string(comboLights[i].GetCurrentLight().getPosition().x) << " , " << std::to_string(comboLights[i].GetCurrentLight().getPosition().y) << std::endl;
	}
}
