#include "CollisionSystem.hpp"
#include "GUI.hpp"
#include "Player.hpp"
#include "spell.hpp"
#include "Spellbook.hpp"
#include "SpellGraphics.hpp"
#include "Textures.hpp"
#include <SFML/Graphics.hpp>
#include <print>
#include <iostream>
#include "EnemySpawner.hpp"
#include "Casting_Combo_GUI.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Main Window");
	sf::Event e;

	Textures textures;
	Player player(textures.GetPlayerTexture());
	GUI gui(player);
	SpellGraphics spellEffects;
	CollisionSystem collisionSystem;
	EnemySpawner enemySpawner;
	Casting_Combo_GUI castingGUI(player);

	// Legacy test target===
	//sf::RectangleShape testTarget;	
	//testTarget.setSize(sf::Vector2f(50, 50));
	//testTarget.setFillColor(sf::Color::Green);
	//testTarget.setOutlineColor(sf::Color::White);
	//testTarget.setOrigin(testTarget.getGlobalBounds().width / 2, testTarget.getGlobalBounds().height / 2);
	//testTarget.setPosition(500, 500);
	// Legacy test target===


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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && !player.IsCasting())
				{
					player.SetIsCastingTrue();
				}
			}

			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && player.IsCasting())
			{
				player.SetIsCastingFalse();
				player.GetSpellBook().ResetComboInput();
				castingGUI.ResetAllLights();	
			}

			if (!player.IsSpellInHand())
			{
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W && player.IsCasting())
				{
					int directionCode = 1;//UP
					player.GetSpellBook().SpellComboInput(directionCode, castingGUI);
				}
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::S && player.IsCasting())
				{
					int directionCode = 2;//DOWN
					player.GetSpellBook().SpellComboInput(directionCode, castingGUI);
				}
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::A && player.IsCasting())
				{
					int directionCode = 3;//LEFT
					player.GetSpellBook().SpellComboInput(directionCode, castingGUI);
				}
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::D && player.IsCasting())
				{
					int directionCode = 4;//RIGHT
					player.GetSpellBook().SpellComboInput(directionCode, castingGUI);
				}
			}

			if ((e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && player.IsSpellInHand()))
			{
				std::cout << "click detected" << std::endl;

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f spellTarget(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

				player.GetSpellBook().CastSpell(spellTarget, player.GetSpellBook().GetSpellInHand(), player, spellEffects, castingGUI);
			}
		}

		//Movement logic
		player.ResetPlayerVelocity();

		if (!player.IsCasting())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				player.GetPlayerVelocity().y -= (player.GetMovementSpeed());
				//player.GetSprite().move(0, -player.GetMovementSpeed() * deltaTime);
				//std::cout << "W pressed, velocity is " << player.GetPlayerVelocity().x << ", " << player.GetPlayerVelocity().y << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				player.GetPlayerVelocity().y += (player.GetMovementSpeed());
				//std::cout << "S pressed, velocity is " << playerVelocity.x << ", " << playerVelocity.y << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				player.GetPlayerVelocity().x -= (player.GetMovementSpeed());
				//std::cout << "A pressed, velocity is " << playerVelocity.x << ", " << playerVelocity.y << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				player.GetPlayerVelocity().x += (player.GetMovementSpeed());
				//std::cout << "D pressed, velocity is " << playerVelocity.x << ", " << playerVelocity.y << std::endl;
			}

			player.GetSprite().move(player.GetPlayerVelocity().x * frame_time.asSeconds(), player.GetPlayerVelocity().y * frame_time.asSeconds());
		}

		//Do things

		player.SetSpellInHand(player.GetSpellBook().IsSpellInHand());//sets player spell in hand to match up with the spellbook

		if (player.IsSpellInHand())
		{
			player.SetIsCastingFalse();
		}
		
		spellEffects.UpdateSpellPositions();
		enemySpawner.SpawnEnemies();
		enemySpawner.UpdatePosition(player, frame_time);

		//Collission Detection

		//Not really sure how to approach this, as there are so many different sorts of collisions I need to deal with, some unique ones are;defrhgnolzsedhngbloszirdnjhgliksnj

		// Fireball with an Icewall
		// Fireball with an Enemy
		// Enemy with an Icewall

		collisionSystem.CheckForOverlaps(spellEffects.fireballEffects, spellEffects.icewallEffects, enemySpawner.GetEnemies(), player);//checks for overlaps between enemy-fireballs-icewalls.


		//Update GUI draw values

		gui.UpdateFpsText(1 / frame_time.asSeconds());
		gui.UpdateFireBallGUIPosition(player);


		// Clear window
		window.clear(sf::Color::Black);

		// Draw everything
		window.draw(player.GetSprite());
		window.draw(gui.GetFpsText());
		castingGUI.DrawLights(player.GetSpellBook().GetCurrentCastCombo(), window);

		for (size_t i = 0; i < enemySpawner.GetEnemies().size(); i++)
		{
			window.draw(enemySpawner.GetEnemies()[i].GetSprite());
		}

		//window.draw(testTarget);

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

		spellEffects.DrawSpellEffects(window);

		// Display the draw buffer
		window.display();
	}

	return 0;
}


