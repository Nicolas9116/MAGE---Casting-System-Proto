#pragma once
#include <SFML/Graphics.hpp>
#include "Spellbook.hpp"


class Player
{
public:
    Player(const sf::Texture& playerTex);
    void draw(sf::RenderWindow& window);
    bool IsCasting() const;

    void SetIsCastingTrue();
    void SetIsCastingFalse();
    sf::Sprite& GetSprite();
    float GetMovementSpeed() const;
    Spellbook& GetSpellBook();
    void SetSpellInHand(bool isSpellInHand);
    const bool IsSpellInHand() const;

private:

    const sf::Texture& playerTexture;
    sf::Sprite playerSprite;
    Spellbook playerSpellbook;
    bool isCasting = false;
    float movementSpeed = 200;
    bool spellInHand = false;

    Fireball fireballSpell;
    Icewall icewallSpell;
    Teleport teleportSpell;
};
