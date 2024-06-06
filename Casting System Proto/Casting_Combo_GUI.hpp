#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"


class Casting_Combo_GUI
{
public:
//This class should be driving the whole thing, it has pretty well everything needed to do so, and I am not sure why I abstracted the
//Spells away from this class--they can just be an (unordered_map)?? that houses the string name, and vector of lights constructed
//from the reference to the spellbook's spellcombos map. IE, iterate through the spellbook and for each spell, take the second value, turn
//it into lights, copy the first value as the name of that row---probably use this first value later for setting text for each combo, IE
// FIREBALL UP RIGHT RIGHT <---on the interface. 


	Casting_Combo_GUI(Player& player);
	
	sf::Texture litTexUp;
	sf::Texture unlitTexUp;

	void DrawLights(std::vector<int> currentInputCombo, sf::RenderWindow& window);

	std::vector<SpellCombo>& GetSpellComboVector();
	void ResetAllLights();
	void SetupComboLights(std::unordered_map < std::string, std::vector<int>>& spellCombos)

	void UpdateLightStates(std::vector<int>& currentCombo);
	void DrawCastingGUILights(std::vector<int>& currentCombo, sf::RenderWindow& window);

private:
	int xOffset;
	int yOffset;
	sf::vector2f startingGUIPos = sf::vector2f(50, 200);
	std::unordered_map < std::string, std::vector<int>>& spellCombos;
	std::unordered_map < std::string, std::vector<ComboLights> spellComboGUI;
	bool isCasting = false;
};

