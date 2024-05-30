#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpellGraphics.hpp"

class Player;

// Base class for spells
class Spell
{
private:

public:
	virtual ~Spell() = default;
	virtual void Cast(sf::Vector2i spellTarget, Player& player, SpellGraphics& spellEffects) = 0;  // Pure virtual function
	virtual int& GetSpellCharges() =0;
	virtual void ResetSpellCharges() =0;
};

// Derived classes for specific spells
class Fireball : public Spell
{
private:
	int spellCharges = 3;
	int maxSpellCharges = 3;

public:

	void Cast(sf::Vector2i spellTarget, Player& player, SpellGraphics& spellEffects) override
	{
		spellCharges -= 1;
		std::cout << "Casting Fireball at (" << spellTarget.x << ", " << spellTarget.y << ")!" << std::endl;
		std::cout << spellCharges << std::endl;
		spellEffects.fireballEffects.emplace_back(spellTarget, player);
	}

	int& GetSpellCharges() override
	{
		return spellCharges;
	}

	void ResetSpellCharges() override
	{
		spellCharges = maxSpellCharges;
	}
};

class Icewall : public Spell
{
private:
	int spellCharges = 1;
	int maxSpellCharges = 1;
public:
	void Cast(sf::Vector2i spellTarget, Player& player, SpellGraphics& spellEffects) override {
		std::cout << "Casting Icewall at (" << spellTarget.x << ", " << spellTarget.y << ")!" << std::endl;
		spellCharges -= 1;
		std::cout << spellCharges << std::endl;
	}

	int& GetSpellCharges() override
	{
		return spellCharges;
	}

	void ResetSpellCharges() override
	{
		spellCharges = maxSpellCharges;
	}
};

class Teleport : public Spell
{
private:
	int spellCharges = 1;
	int maxSpellCharges = 1;
public:
	void Cast(sf::Vector2i spellTarget, Player& player, SpellGraphics& spellEffects) override
	{
		std::cout << "Casting Teleport at (" << spellTarget.x << ", " << spellTarget.y << ")!" << std::endl;
		spellCharges -= 1;
		std::cout << spellCharges << std::endl;
	}

	int& GetSpellCharges() override
	{
		return spellCharges;
	}

	void ResetSpellCharges() override
	{
		spellCharges = maxSpellCharges;
	}
};
