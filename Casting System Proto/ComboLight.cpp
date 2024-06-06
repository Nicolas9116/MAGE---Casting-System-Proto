#include "ComboLight.hpp"

	ComboLight::ComboLight(sf::vector2f startingGUIPos,int xOffset,int yOffset,int j//position in vector<int>,int spellCombos[i].second[j]//value of the combo input for arrow rotation, litTex, unLitTex)
	{
		unLitSprite.setTexture(unLitTex);
		LitSprite.setTexture(LitTex);
		
		if(inputValue == 1)
			{
				sf::Sprite currentSprite.setRotation(0);	
			}
		if(inputValue == 2)
			{
				sf::Sprite currentSprite.setRotation(180);	
			}
		if(inputValue == 3)
			{
				sf::Sprite currentSprite.setRotation(270);	
			}
		if(inputValue == 4)
			{
				sf::Sprite currentSprite.setRotation(90);	
			}

		inputValue = spellCombos[i].second[j];
	
		currentLight.setTexture(unLitTex);
		currentLight.setOrigin(currentLight.getSize()/2);
		currentLight.setPosition(sf::vector2f(startingGUIPosition.x + xOffset, startingGUIPosition.y + yOffset));
	}

	void ComboLight::LightOn(sf::Texture& litTex)
	{
		currentLight.setTexture(litTex)
		isLit = true;
	}

	void ComboLight::LightOff(sf::Texture& UnLitTex)
	{
		currentLight.setTexture(UnLitTex);
		isLit = false;
	}

	sf::Sprite& ComboLight::GetCurrentLight()
	{
		return currentLight;
	}

	void ComboLight::SetPosition(sf::Vector2f position)
	{
		currentLight.setPosition(position);

	}
