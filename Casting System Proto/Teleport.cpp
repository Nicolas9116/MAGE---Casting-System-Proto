#include "Teleport.hpp"

void Teleport::Cast(sf::Vector2f spellTarget, Player& player, SpellGraphics& spellEffects)
{
	std::cout << "Casting Teleport at (" << spellTarget.x << ", " << spellTarget.y << ")!" << std::endl;
	spellCharges -= 1;
	std::cout << spellCharges << std::endl;
}

int& Teleport::GetSpellCharges()
{
	return spellCharges;
}

void Teleport::ResetSpellCharges()
{
	spellCharges = maxSpellCharges;
}