#include "Casting_Combo_GUI.hpp"
#include "Player.hpp"

Casting_Combo_GUI::Casting_Combo_GUI(Player& player)
	: spellCombos(player.GetSpellBook().GetSpellCombos())
{
	litTexUp.loadFromFile("C:/Users/vampi/source/repos/Casting System Proto/Sprites/Arrows/Lit_Up.png");
	unlitTexUp.loadFromFile("C:/Users/vampi/source/repos/Casting System Proto/Sprites/Assets/Arrows/UnLit_Up.png");
	SetUpComboLights(spellCombos);
}

Casting_Combo_GUI::UpdateLightStates(std::vector<int> currentCombo)
{
	for (int i = 0; i < SpellComboGUI.size(); i++)
	{	
		for (int j = 0; j < spellComboGui[i].second.size(); j++)
		{
			if(spellComboGUI[i].second[j] == currentCombo[j])
			{
				spellComboGUI[i].second[j].LightOn()
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
	for (int i = 0; i < SpellComboGUI.size(); i++)
	{	
		for (int j = 0; j < spellComboGui[i].second.size(); j++)
		{
			window.draw(spellComboGUI[i].second[j].GetSprite());
		}	
	}
}

void Casting_Combo_GUI::ResetAllLights()
{
	for (int i = 0; i < SpellComboGUI.size(); i++)
	{	
		for (int j = 0; j < spellComboGui[i].second.size(); j++)
		{
			spellComboGUI[i].second[j].TurnOff();
		}	
	}
}

void Casting_Combo_GUI::SetupComboLights(std::unordered_map < std::string, std::vector<int>>& spellCombos)
{
	for(int i=0; i < spellCombos.size(); i++)
		{
			int xOffset = 0;
			for(int j = 0; j < spellCombos[i].second.size(); j++)//I want this to iterate through the members of the vector and add a light for each
				{
					spellComboGUI[i].push_back(spellCombo[i].first, ComboLight(startingGUIPos, xOffset, yOffset,
	 j//position in vector<int>, spellCombos[i].second[j]//value of the combo input for arrow rotation, litTex, unLitTex)	
				}
			xOffset += 200;
		}	
	
}
