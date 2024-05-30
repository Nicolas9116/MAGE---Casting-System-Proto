#pragma once
#include "Player.hpp"

class FireballSpellGraphic;

class SpellGraphics
{
private:
    sf::Texture fireballTex;
    sf::Texture icewallTex;
    sf::Texture teleportTex;

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
    FireballSpellGraphic(sf::Vector2f spellTarget, Player& player);
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
