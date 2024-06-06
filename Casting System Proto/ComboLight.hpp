#pragma once
#include <SFML/Graphics.hpp>

class ComboLight
{
public:
	
	ComboLight(sf::Sprite& litSprite, sf::Sprite& unlitSprite, sf::Texture& litTex, sf::Texture& unLitTex);

	void LightOn();
	void LightOff();
	sf::Sprite& GetCurrentLight();
	bool GetIsLit() { return isLit; }
	void SetPosition(sf::Vector2f position);
	float& GetLightOffset() { return lightOffset; }

private:
	sf::Sprite litSprite;
	sf::Sprite unlitSprite;

	int inputValue;

	sf::Sprite& currentLight;
	float lightOffset = 200;	
	bool isLit = false;
};

