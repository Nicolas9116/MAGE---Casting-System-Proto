#include "Icewall.hpp"


void Icewall::Cast(sf::Vector2f spellTarget, Player& player, SpellGraphics& spellEffects)
{
	std::cout << "Casting Icewall at (" << spellTarget.x << ", " << spellTarget.y << ")!" << std::endl;
	spellCharges -= 1;
	std::cout << spellCharges << std::endl;
	spellEffects.icewallEffects.emplace_back(spellTarget, player);
}

int& Icewall::GetSpellCharges()

{
	return spellCharges;
}

void Icewall::ResetSpellCharges()

{
	spellCharges = maxSpellCharges;
}