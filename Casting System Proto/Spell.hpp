#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpellGraphics.hpp"

class Player;
class Fireball;
class Icewall;
class Teleport;

// Base class for spells
class Spell
{
private:




public:
	virtual ~Spell() = default;
	virtual void Cast(sf::Vector2f spellTarget, Player& player, SpellGraphics& spellEffects) = 0;  // Pure virtual function
	virtual int& GetSpellCharges() =0;
	virtual void ResetSpellCharges() =0;
};




