#include "Spellbook.hpp"
#include "player.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


Spellbook::Spellbook()
{
	spellCombos["Fireball"] = { 1,4,4 };
	spellCombos["Icewall"] = { 2,3,3 };
	spellCombos["Teleport"] = { 2,2,2 };

	spells["Fireball"] = std::make_shared<Fireball>();
	spells["Icewall"] = std::make_shared<Icewall>();
	spells["Teleport"] = std::make_shared<Teleport>();
}

std::vector<int>& Spellbook::GetCurrentCastCombo()
{
	return currentCastCombo;
}

void Spellbook::SpellComboInput(int& directionCode)
{
	GetCurrentCastCombo().push_back(directionCode);

	if (GetCurrentCastCombo().size() > 3)
	{
		ResetComboInput();
		return;
	}

	CheckCurrentCastComboAgainstSpellbook();
}

void Spellbook::ResetComboInput()
{
	GetCurrentCastCombo().clear();
	std::cout << "Combo counter reset" << std::endl;//debug
}

bool Spellbook::CheckCurrentCastComboAgainstSpellbook()
{
	for (const auto& spell : spellCombos) {
		if (CompareCombos(currentCastCombo, spell.second)) {

			std::cout << "Correct combo detected" << std::endl;//debug
			SetSpellInHand(true, spell.first);
			return true;
		}
	}
	return false;
}

bool Spellbook::CompareCombos(const std::vector<int>& combo1, const std::vector<int>& combo2) {
	if (combo1.size() != combo2.size()) {
		return false;
	}
	for (size_t i = 0; i < combo1.size(); ++i) {
		if (combo1[i] != combo2[i]) {
			return false;
		}
	}
	return true;
}

bool Spellbook::IsSpellInHand()
{
	return spellInHand;
}

void Spellbook::SetSpellInHand(bool isSpellInHand, const std::string spellName)
{
	spellInHand = isSpellInHand;

	if (isSpellInHand == true)
	{
		spellInHandName = spellName;
	}
	else
	{
		spellInHandName.clear();
	}
}

void Spellbook::SpellNotInHand()
{
	spellInHand = false;
	spellInHandName.clear();
}

std::string& Spellbook::GetSpellInHand()
{
	return spellInHandName;
}

void Spellbook::CastSpell(sf::Vector2i spellTarget, const std::string& spellname) {
	auto it = spells.find(spellname);
	if (it != spells.end()) 
	{
		it->second->Cast(spellTarget);

		if (it->second->GetSpellCharges() == 0)
		{
		std::cout << "spell charges detected at 0" << std::endl;
			SpellNotInHand();
			it->second->ResetSpellCharges();
		}
	}
	else {
		std::cout << "Spell not found!" << std::endl;
	}
}
