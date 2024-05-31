#include "Fireball.hpp"

void Fireball::Cast(sf::Vector2f spellTarget, Player& player, SpellGraphics& spellEffects)
{
GetSpellCharges() -= 1;
std::cout << "Casting Fireball at (" << spellTarget.x << ", " << spellTarget.y << ")!" << std::endl;
std::cout << spellCharges << std::endl;
spellEffects.fireballEffects.emplace_back(spellTarget, player);
}

int& Fireball::GetSpellCharges()
{
	return spellCharges;
}

void Fireball::ResetSpellCharges()
{
	spellCharges = maxSpellCharges;
}