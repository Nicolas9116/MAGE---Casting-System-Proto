#pragma once
#include <SFML/Graphics.hpp>

class ComboLight
{
public:
	
	ComboLight(sf::Sprite& litSprite, sf::Sprite& unlitSprite);

	void LightOn();
	void LightOff();
	sf::Sprite& GetCurrentLight();
	bool GetIsLit() { return isLit; }
	void SetPosition(sf::Vector2f position);
	float& GetLightOffset() { return lightOffset; }

private:
	sf::Sprite& litSprite;
	sf::Sprite& unlitSprite;

	sf::Sprite currentLight;
	float lightOffset = 200;	
	bool isLit = false;
};

