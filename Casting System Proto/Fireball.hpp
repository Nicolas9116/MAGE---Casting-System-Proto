#pragma once
#include "GUI.hpp"

class Fireball
{
public:
    Fireball();

    void UpdateCombo(int& direction);          // Update the combo input state
    bool isComboComplete() const; // Check if the combo is complete
    void ResetComboState();

    sf::CircleShape shape;
    float lifespan;

private:
    enum class ComboState
    {
        None,
        Up,
        UpRight,
        UpRightRight
    };

    ComboState comboState;
};
