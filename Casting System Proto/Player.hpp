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
    sf::Vector2f& GetPlayerVelocity();
    void ResetPlayerVelocity();
    void TakeDamage(int damage);    

private:
    int health = 3;
    const sf::Texture& playerTexture;
    sf::Sprite playerSprite;
    Spellbook playerSpellbook; // Ensure Spellbook is correctly included and used
    bool isCasting = false;
    float movementSpeed = 100; // Use float suffix
    bool spellInHand = false;
    sf::Vector2f velocity = sf::Vector2f (0, 0);

};          