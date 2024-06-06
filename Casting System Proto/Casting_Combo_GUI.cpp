#include "Casting_Combo_GUI.hpp"
#include "Player.hpp"

Casting_Combo_GUI::Casting_Combo_GUI(Player& player)
	: spellCombos(player.GetSpellBook().GetSpellCombos())
{
	xOffset = 40;
	yOffset = 40;

	litTexUp.loadFromFile("C:/Users/vampi/source/repos/Casting System Proto/Sprites/Arrows/Lit_Up.png");
	unlitTexUp.loadFromFile("C:/Users/vampi/source/repos/Casting System Proto/Sprites/Arrows/UnLit_Up.png");
	SetupComboLights(spellCombos);
}

void Casting_Combo_GUI::UpdateLightStates(std::vector<int>& currentCombo)
{
	for (auto& pair : spellComboGUI)
	{
		for (int j = 0; j < pair.second.size(); j++)
		{

			if (j >= currentCombo.size()) {

				break;
			}

			if (pair.second[j].GetInputValue() == currentCombo[j])
			{
				pair.second[j].LightOn();
			}
			else
			{
				break;
			}
		}
	}
}

void Casting_Combo_GUI::DrawCastingGUILights(sf::RenderWindow& window)
{
	for (auto& pair : spellComboGUI)
	{
		for (int j = 0; j < pair.second.size(); j++)
		{
			window.draw(pair.second[j].GetCurrentLight());
		}
	}
}

void Casting_Combo_GUI::ResetAllLights()
{
	for (auto& pair : spellComboGUI)
	{
		for (int j = 0; j < pair.second.size(); j++)
		{
			pair.second[j].LightOff();
		}
	}
}

void Casting_Combo_GUI::SetupComboLights(std::unordered_map<std::string, std::vector<int>>& spellCombos)
{
	for (auto& pair : spellCombos)
	{
		std::cout << yOffset << " , " << xOffset << std::endl;


		std::vector<ComboLight> comboLights;
		for (int j = 0; j < pair.second.size(); j++)
		{
			comboLights.push_back(ComboLight(startingGUIPos, xOffset, yOffset, j, pair.second[j], litTexUp, unlitTexUp));
			//yOffset += 20;
		}
		yOffset += 40;

		spellComboGUI.insert({ pair.first, comboLights });
	}
}