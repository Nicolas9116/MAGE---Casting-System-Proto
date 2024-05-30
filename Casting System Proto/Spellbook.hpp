#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>  // For std::shared_ptr
#include "Spells.hpp"  // Include the Spell header
#include "Player.hpp"

class Spellbook
{
private:
	std::unordered_map < std::string, std::vector<int>> spellCombos;//spellbook
	std::unordered_map<std::string, std::shared_ptr<Spell>> spells;//pointers to spell methods
	std::vector<int> currentCastCombo;//vector to track current cast

	bool spellInHand = false;
	std::string spellInHandName;

public:

	Spellbook();

	std::vector<int>& GetCurrentCastCombo();//fetch reference to currentCastCombo
	void SpellComboInput(int& directionCode);//Takes in direction input (1up,2down,3left,4right)
	void ResetComboInput();//Reset the currentCastCombo to empty vector
	bool CheckCurrentCastComboAgainstSpellbook();//true if successfull spell cast
	bool CompareCombos(const std::vector<int>& combo1, const std::vector<int>& combo2);//compare currentcombo with spellbook combos
	void CastSpell(sf::Vector2i spellTarget, const std::string& spellname, Player& player, SpellGraphics& spellEffects);//

	void SetSpellInHand(bool isSpellInHand, const std::string spellName);
	bool IsSpellInHand();
	void SpellNotInHand();

	std::unordered_map<std::string, std::shared_ptr<Spell>> GetSpells();

	std::string& GetSpellInHand();
};