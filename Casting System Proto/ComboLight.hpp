#pragma once
#include <SFML/Graphics.hpp>

class ComboLight
{
public:
    ComboLight(sf::Vector2f startingGUIPos, int& xOffset, int& yOffset, int j, int& inputValue, sf::Texture& litTex, sf::Texture& unLitTex);

    void LightOn();
    void LightOff();
    sf::Sprite GetCurrentLight();
    bool GetIsLit() const { return isLit; }
    int& GetInputValue() { return inputValue; } 

private:
    sf::Texture& litTex;
    sf::Texture& unLitTex;

    int inputValue;

    sf::Sprite currentLight;
    bool isLit = false;
};

