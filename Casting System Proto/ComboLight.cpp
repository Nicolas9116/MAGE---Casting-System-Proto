#include "ComboLight.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
ComboLight::ComboLight(sf::Vector2f startingGUIPos, int& xOffset, int& yOffset, int j, int& inputValue, sf::Texture& litTex, sf::Texture& unLitTex)
    : litTex(litTex), unLitTex(unLitTex), inputValue(inputValue), currentLight(unLitTex)
{
    std::cout << xOffset << " , " << yOffset << std::endl;
    std::cout << "StartingGUIPos is " << std::to_string(startingGUIPos.x) << " , " << std::to_string(startingGUIPos.y) << std::endl;

    currentLight.setOrigin(sf::Vector2f(currentLight.getTexture()->getSize()) / 2.f);
    currentLight.setPosition(startingGUIPos.x + (j * xOffset), startingGUIPos.y + yOffset);

    std::cout << std::to_string(currentLight.getPosition().x) << " , " << std::to_string(currentLight.getPosition().y) << std::endl;

    if (inputValue == 1)
    {
        currentLight.setRotation(0);
    }
    else if (inputValue == 2)
    {
        currentLight.setRotation(180);
    }
    else if (inputValue == 3)
    {
        currentLight.setRotation(270);
    }
    else if (inputValue == 4)
    {
        currentLight.setRotation(90);
    }
}

void ComboLight::LightOn()
{
    currentLight.setTexture(litTex);
    isLit = true;
}

void ComboLight::LightOff()
{
    currentLight.setTexture(unLitTex);
    isLit = false;
}

sf::Sprite ComboLight::GetCurrentLight()
{
    return currentLight;
}