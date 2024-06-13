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

	sf::Texture fireBallTex;
	sf::Texture icewallTex;
	std::vector<FireballSpellGraphic> fireballEffects;
	std::vector<IcewallSpellGraphic> icewallEffects;
	//std::vector<TeleportSpellEffect> teleportEffects;

	void UpdateSpellPositions(sf::Time& frame_time);
	void DrawSpellEffects(sf::RenderWindow& window);
};

class FireballSpellGraphic : public SpellGraphics
{
private:

	bool markedForDeletion = false;

	sf::Sprite fireballSprite;

	sf::Vector2f direction;
	sf::Vector2f velocity;
	float speed = 600;
	sf::Clock fireballDurationClock;
	int fireballDuration = 2;
	float spellDamage = 10;

public:
	// Constructor declaration
	FireballSpellGraphic(sf::Vector2f spellTarget, Player& player, sf::Texture& fireballTex);

	sf::Sprite& fireballGraphics();
	void UpdatePosition(sf::Time& frame_time);
	bool ShouldBeDeleted() const;
	float& GetSpellDamage();
	void MarkForDeletion();
};



class IcewallSpellGraphic : public SpellGraphics
{
private:

	sf::Sprite icewallSprite;
	bool markedForDeletion = false;
	sf::Clock icewallDurationClock;
	int icewallDuration = 5;

public:

	IcewallSpellGraphic(sf::Vector2f spellTarget, Player& player, sf::Texture& icewallTex);
	void UpdatePosition();
	bool ShouldBeDeleted() const;
	sf::Sprite& icewallGraphics();
};



//class TeleportSpellEffect : public SpellGraphics
//{
//private:
//    // Add any member variables here if needed
//
//public:
//    // Add any member functions here if needed
//};

