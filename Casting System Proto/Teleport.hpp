#pragma once
#include "Spell.hpp"

class Teleport : public Spell
{
private:
	int spellCharges = 1;
	int maxSpellCharges = 1;
public:
	void Cast(sf::Vector2f spellTarget, Player& player, SpellGraphics& spellEffects) override;
	int& GetSpellCharges() override;
	void ResetSpellCharges() override;
};
