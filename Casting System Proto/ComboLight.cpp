#include "ComboLight.hpp"


	ComboLight::ComboLight(sf::Sprite& litSprite, sf::Sprite& unlitSprite)
		: litSprite(litSprite), unlitSprite(unlitSprite), currentLight(unlitSprite)
	{
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
