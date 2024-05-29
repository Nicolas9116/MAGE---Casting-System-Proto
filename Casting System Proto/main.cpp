#include <SFML/Graphics.hpp>
#include "Textures.hpp"
#include "Player.hpp"
#include "GUI.hpp"
#include "Spellbook.hpp"
#include "spells.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Main Window");
	sf::Event e;


	Textures textures;
	Player player(textures.GetPlayerTexture());
	GUI gui(player);

	sf::Clock frameRateClock;

	while (window.isOpen())
	{
		auto frame_time = frameRateClock.restart();

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}

			if (!player.IsSpellInHand())
			{
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W && player.IsCasting())
				{
					int directionCode = 1;//UP
					player.GetSpellBook().SpellComboInput(directionCode);
				}
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::S && player.IsCasting())
				{
					int directionCode = 2;//DOWN
					player.GetSpellBook().SpellComboInput(directionCode);
				}
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::A && player.IsCasting())
				{
					int directionCode = 3;//LEFT
					player.GetSpellBook().SpellComboInput(directionCode);
				}
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::D && player.IsCasting())
				{
					int directionCode = 4;//RIGHT
					player.GetSpellBook().SpellComboInput(directionCode);
				}
			}

			if ((e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && player.IsSpellInHand()))
			{
				std::cout << "click detected" << std::endl;
				auto spellTarget = sf::Mouse::getPosition(window);
				player.GetSpellBook().CastSpell(spellTarget, player.GetSpellBook().GetSpellInHand());
			}
		}

		//Game logic

		if (!player.IsSpellInHand())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && !player.IsCasting())
			{
				player.SetIsCastingTrue();
			}
		}

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && player.IsCasting())
		{
			player.SetIsCastingFalse();
			player.GetSpellBook().ResetComboInput();
		}


		if (!player.IsCasting())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				player.GetSprite().move(0, -player.GetMovementSpeed() * frame_time.asSeconds());
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				player.GetSprite().move(0, player.GetMovementSpeed() * frame_time.asSeconds());
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				player.GetSprite().move(-player.GetMovementSpeed() * frame_time.asSeconds(), 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				player.GetSprite().move(player.GetMovementSpeed() * frame_time.asSeconds(), 0);
			}
		}
		//Do things

		player.SetSpellInHand(player.GetSpellBook().IsSpellInHand());//sets player spell in hand to match up with the spellbook

		if (player.IsSpellInHand())
		{
			player.SetIsCastingFalse();
		}


		//Update GUI draw values

		gui.UpdateFpsText(1 / frame_time.asSeconds());
		//gui.UpdateFireBallGUIPosition(player);


		// Clear window
		window.clear(sf::Color::Black);

		// Draw everything
		window.draw(player.GetSprite());
		window.draw(gui.GetFpsText());

		// Display the draw buffer
		window.display();


	}

	return 0;
}


