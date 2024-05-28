#pragma once
#include <SFML/Graphics.hpp>
#include "Fireball.hpp"

class Player
{
public:
    Player(const sf::Texture& playerTex);
    void Update(int& direction);
    void draw(sf::RenderWindow& window);
    bool IsCasting() const;

    void SetIsCastingTrue();
    void SetIsCastingFalse();
    sf::Sprite& GetSprite();
    float GetMovementSpeed() const;
    bool IsFireBallInHand();
    void CastFireBall(sf::Vector2i& fireballTarget);
    void UpdateFireballs(float deltaTime);
    std::vector<Fireball>& GetActiveFireballs();

private:
    const sf::Texture& playerTexture;
    sf::Sprite playerSprite;
    bool isCasting = false;
    float movementSpeed = 200;
    bool fireballInHand = false;
    int fireballsInHand = 0;
    int maxFireballs = 3;

    std::vector<Fireball> activeFireballs;
};
