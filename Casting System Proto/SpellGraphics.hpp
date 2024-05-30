#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class FireballSpellGraphic;
class Player;

class SpellGraphics
{
private:

public:
    std::vector<FireballSpellGraphic> fireballEffects;
    //std::vector<IcewallSpellEffect> icewallEffects;
    //std::vector<TeleportSpellEffect> teleportEffects;



};

class FireballSpellGraphic : public SpellGraphics
{
private:
    sf::CircleShape fireballSprite;

public:
    // Constructor declaration
    FireballSpellGraphic(sf::Vector2i spellTarget, Player& player);
    sf::CircleShape& fireballgraphics();
    // Add any other member functions or variables here if needed
};

//class IcewallSpellEffect : public SpellGraphics
//{
//private:
//    // Add any member variables here if needed
//
//public:
//    // Add any member functions here if needed
//};
//
//class TeleportSpellEffect : public SpellGraphics
//{
//private:
//    // Add any member variables here if needed
//
//public:
//    // Add any member functions here if needed
//};

