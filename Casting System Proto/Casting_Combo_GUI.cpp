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
