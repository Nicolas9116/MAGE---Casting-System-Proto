#pragma once
#include <SFML/Graphics.hpp>
#include "SpellCombo.hpp"
#include "Player.hpp"


class Casting_Combo_GUI
{
public:

	Casting_Combo_GUI(Player& player);
	
	sf::Texture litTexUp;
	sf::Texture unlitTexUp;

	void DrawLights(std::vector<int> currentInputCombo, sf::RenderWindow& window);

	sf::Sprite upLit;
	sf::Sprite upUnlit;

	sf::Sprite downLit;
	sf::Sprite downUnlit;

	sf::Sprite rightLit;
	sf::Sprite rightUnlit;

	sf::Sprite leftLit;
	sf::Sprite leftUnlit;

	std::vector<SpellCombo>& GetSpellComboVector();
	void ResetAllLights();

private:

	std::unordered_map < std::string, std::vector<int>>& spellCombos;
	std::vector<SpellCombo> spells;
	bool isCasting = false;


};

