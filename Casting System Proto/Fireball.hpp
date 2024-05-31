#pragma once
#include "Spell.hpp"

class Fireball : public Spell
{
private:
	int spellCharges = 3;
	int maxSpellCharges = 3;

public:

	void Cast(sf::Vector2f spellTarget, Player& player, SpellGraphics& spellEffects) override;

	int& GetSpellCharges() override;

	void ResetSpellCharges() override;

};

