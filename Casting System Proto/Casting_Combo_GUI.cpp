#include "Casting_Combo_GUI.hpp"
#include "SpellCombo.hpp"
#include "Player.hpp"

Casting_Combo_GUI::Casting_Combo_GUI(Player& player)
	: spellCombos(player.GetSpellBook().GetSpellCombos())
{
	litTexUp.loadFromFile("C:/Users/vampi/source/repos/Casting System Proto/Sprites/Arrows/Lit_Up.png");
	unlitTexUp.loadFromFile("C:/Users/vampi/source/repos/Casting System Proto/Sprites/Assets/Arrows/UnLit_Up.png");

	upLit.setTexture(litTexUp);
	upUnlit.setTexture(unlitTexUp);

	downLit.setTexture(litTexUp);
	downLit.rotate(180);
	downUnlit.setTexture(unlitTexUp);
	downLit.rotate(180);

	rightLit.setTexture(litTexUp);
	rightLit.rotate(90);
	rightUnlit.setTexture(unlitTexUp);
	rightLit.rotate(90);

	leftLit.setTexture(litTexUp);
	leftLit.rotate(270);
	leftUnlit.setTexture(unlitTexUp);
	leftLit.rotate(270);

	for (const auto& spell : spellCombos)
	{
		spells.push_back(SpellCombo(spell.second, spell.first, upLit, upUnlit, downLit, downUnlit, rightLit, rightUnlit, leftLit, leftUnlit));
	}
}


void Casting_Combo_GUI::DrawLights(std::vector<int> currentInputCombo, sf::RenderWindow& window)
{
	for (int i = 0; i < spells.size(); i++)
	{
		spells[i].CheckCurrentComboCompletion(currentInputCombo);
		spells[i].DrawComboLights(window);
	}
}

std::vector<SpellCombo>& Casting_Combo_GUI::GetSpellComboVector()
{
	return spells;
}

void Casting_Combo_GUI::ResetAllLights()
{
	for (int i = 0; i < spells.size(); i++)
	{
		for (int j = 0; j < spells[i].comboLights.size(); j++)
		{
			spells[i].comboLights[j].LightOff();
		}
	}
}

void Casting_Combo_GUI::SetupComboLights(std::unordered_map < std::string, std::vector<int>>& spellCombos, 
				std::unordered_map < std::string, std::vector<ComboLights> spellComboGUI)
{
	for(int i=0; i < spellCombos.size(); i++)
		{
			int xOffset = 0;
			for(int j = 0; j < spellCombos[i].second.size(); j++)//I want this to iterate through the members of the vector and add a light for each
				{
					spellComboGUI[i].push_back(spellCombo[i].first, ComboLight(startingGUIPos, xOffset, yOffset, j//position in vector<int>, spellCombos[i].second[j]//value of the combo input for arrow rotation)	
				}
			xOffset += 200;
		}	
	
}
