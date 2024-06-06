#include "ComboLight.hpp"


	ComboLight::ComboLight(sf::Sprite& litSprite, sf::Sprite& unlitSprite, sf::Texture& litTex, sf::Texture& unLitTex)
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

		currentLight& = unLitSprite;
	}

	void ComboLight::LightOn()
	{
		currentLight = litSprite;
		isLit = true;
	}

	void ComboLight::LightOff()
	{
		currentLight = unlitSprite;
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
