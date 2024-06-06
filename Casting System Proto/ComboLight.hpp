#pragma once
#include <SFML/Graphics.hpp>

class ComboLight
{
public:
	
	ComboLight(sf::vector2f startingGUIPos,int xOffset,int yOffset,int j//position in vector<int>,int spellCombos[i].second[j]//value of the combo input for arrow rotation, litTex, unLitTex);

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
	bool isLit = false;
};

