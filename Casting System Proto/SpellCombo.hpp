#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include "ComboLight.hpp"	

class SpellCombo
{
public:

	SpellCombo(const std::vector<int>& combo, const std::string spellName, sf::Sprite& upLit, sf::Sprite& upUnlit, 
		sf::Sprite& downLit, sf::Sprite& downUnlit, sf::Sprite& rightLit, sf::Sprite& rightUnlit, sf::Sprite& leftLit, sf::Sprite& leftUnlit);

	std::vector<int> correctCombo;
	std::vector<ComboLight> comboLights;

	sf::Sprite& upLit;
	sf::Sprite& upUnlit;

	sf::Sprite& downLit;
	sf::Sprite& downUnlit;
	
	sf::Sprite& rightLit;
	sf::Sprite& rightUnlit;

	sf::Sprite& leftLit;
	sf::Sprite& leftUnlit;

	void CheckCurrentComboCompletion(std::vector<int> currentInputCombo);
	void DrawComboLights(sf::RenderWindow& window);

private:
	 
	float yOffset = 0;	
	std::string spellName;

};

