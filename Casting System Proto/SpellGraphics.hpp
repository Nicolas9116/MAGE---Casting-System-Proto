#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class FireballSpellGraphic;
class IcewallSpellGraphic;
class Player;

class SpellGraphics
{
private:

public:
	SpellGraphics();

	sf::Texture fireBallSprite;
	std::vector<FireballSpellGraphic> fireballEffects;
	std::vector<IcewallSpellGraphic> icewallEffects;
	//std::vector<TeleportSpellEffect> teleportEffects;

	void UpdateSpellPositions();
	void DrawSpellEffects(sf::RenderWindow& window);
};

class FireballSpellGraphic : public SpellGraphics
{
private:

	bool markedForDeletion = false;

	sf::Sprite fireballSprite;
	sf::Vector2f direction;
	sf::Vector2f velocity;
	float speed = .1;
	sf::Clock fireballDurationClock;
	int fireballDuration = 2;
	float spellDamage = 10;

public:
	// Constructor declaration
	FireballSpellGraphic(sf::Vector2f spellTarget, Player& player, sf::Texture& fireballTex);

	sf::Sprite& fireballGraphics();
	void UpdatePosition();
	bool ShouldBeDeleted() const;
	float& GetSpellDamage();
	void MarkForDeletion();
};



class IcewallSpellGraphic : public SpellGraphics
{
private:
	sf::RectangleShape icewallShape;

	bool markedForDeletion = false;
	sf::Clock icewallDurationClock;
	int icewallDuration = 5;

public:

	IcewallSpellGraphic(sf::Vector2f spellTarget, Player& player);
	void UpdatePosition();
	bool ShouldBeDeleted() const;
	sf::RectangleShape& icewallGraphics();
};



//class TeleportSpellEffect : public SpellGraphics
//{
//private:
//    // Add any member variables here if needed
//
//public:
//    // Add any member functions here if needed
//};

