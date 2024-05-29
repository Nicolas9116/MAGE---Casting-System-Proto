#include "Fireball.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "GUI.hpp"

Fireball::Fireball() : comboState(ComboState::None)

{

}

void Fireball::UpdateCombo(int& direction)
{
	if (direction == 1)//UP
	{
		if (comboState == ComboState::None)
		{
			comboState = ComboState::Up;
			std::cout << "up entered" << std::endl;
			return;
		}
		else
		{
			ResetComboState();
		}
	}
	if (direction == 2)//DOWN
	{
		ResetComboState();
	}
	if (direction == 3)//LEFT
	{
		ResetComboState();
	}
	if (direction == 4)//RIGHT
	{
		if (comboState == ComboState::Up)
		{
			comboState = ComboState::UpRight;
			std::cout << "right entered first time" << std::endl;
			return;
		}
		if (comboState == ComboState::UpRight)
		{
			comboState = ComboState::UpRightRight;
			std::cout << "right entered second time" << std::endl;
			return;
		}
		else
		{
			ResetComboState();
		}
	}
}

bool Fireball::isComboComplete() const
{
	return comboState == ComboState::UpRightRight;
}

void Fireball::ResetComboState()
{
	comboState = ComboState::None;
	std::cout << "Combo Reset" << std::endl;
}
