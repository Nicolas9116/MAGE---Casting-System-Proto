#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>  // For std::shared_ptr
#include "Spell.hpp"  // Include the Spell header
#include "Fireball.hpp"
#include "Icewall.hpp"
#include "Teleport.hpp"

class Player;
class SpellGraphics;
class Casting_Combo_GUI;

class Spellbook
{
private:
	std::unordered_map < std::string, std::vector<int>> spellCombos;//spellbook
	std::unordered_map <std::string, std::shared_ptr<Spell>> spells;//pointers to spell methods
	std::vector<int> currentCastCombo;//vector to track current cast

	bool spellInHand = false;
	std::string spellInHandName;

public:

	Spellbook();
	std::unordered_map < std::string, std::vector<int>>& GetSpellCombos();//fetch reference to spellCombos
	std::vector<int>& GetCurrentCastCombo();//fetch reference to currentCastCombo
	void SpellComboInput(int& directionCode, Casting_Combo_GUI castingGUI);//Takes in direction input (1up,2down,3left,4right)
	void ResetComboInput();//Reset the currentCastCombo to empty vector
	bool CheckCurrentCastComboAgainstSpellbook();//true if successfull spell cast
	bool CompareCombos(const std::vector<int>& combo1, const std::vector<int>& combo2);//compare currentcombo with spellbook combos
	bool IsSpellInHand();
	void SpellNotInHand();
	std::unordered_map<std::string, std::shared_ptr<Spell>> GetSpells();
	std::string& GetSpellInHand();
	void SetSpellInHand(bool isSpellInHand, const std::string spellName);
	void CastSpell(sf::Vector2f& spellTarget, const std::string& spellname, Player& player, SpellGraphics& spellEffects, Casting_Combo_GUI& castingGUI);
};