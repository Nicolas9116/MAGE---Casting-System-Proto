#include "GUI.hpp"
#include "Player.hpp"
#include "spell.hpp"
#include "Spellbook.hpp"
#include "SpellGraphics.hpp"
#include "Textures.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Main Window");
	sf::Event e;


	Textures textures;
	Player player(textures.GetPlayerTexture());
	GUI gui(player);
	SpellGraphics spellEffects;

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
				player.GetSpellBook().CastSpell(spellTarget, player.GetSpellBook().GetSpellInHand(), player, spellEffects);
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
		gui.UpdateFireBallGUIPosition(player);


		// Clear window
		window.clear(sf::Color::Black);

		// Draw everything
		window.draw(player.GetSprite());
		window.draw(gui.GetFpsText());

		if (player.IsSpellInHand())
		{
			auto spellbook = player.GetSpellBook();
			auto spells = spellbook.GetSpells();
			auto spellInHand = spellbook.GetSpellInHand();

			auto it = spells.find(spellInHand);
			if (it != spells.end() && it->second != nullptr)
			{
				int chargesLeft = it->second->GetSpellCharges();

				// Loop over the number of charges left
				for (int i = 0; i < chargesLeft; i++)
				{
					// Ensure that the index is within the bounds of SpellAmmoGUI
					if (i < gui.SpellAmmoGUI.size())
					{
						window.draw(gui.SpellAmmoGUI[i]);
					}
					else
					{
						// Handle the case if the index is out of bounds
						// std::cerr << "Index out of bounds for gui.SpellAmmoGUI" << std::endl;
					}
				}
			}
		}

		if (spellEffects.fireballEffects.size() > 0)
		{
			for (size_t i = 0; i < spellEffects.fireballEffects.size(); ++i)
			{
				window.draw(spellEffects.fireballEffects[i].fireballgraphics());
			}
		}
		// Display the draw buffer
		window.display();


	}

	return 0;
}


