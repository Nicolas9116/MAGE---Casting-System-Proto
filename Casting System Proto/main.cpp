#include <SFML/Graphics.hpp>
#include "Textures.hpp"
#include "Player.hpp"
#include "Fireball.hpp"
#include "GUI.hpp"

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
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W && player.IsCasting())
			{
				int directionCode = 1;//UP
				player.Update(directionCode);
			}
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::S && player.IsCasting())
			{
				int directionCode = 2;//DOWN
				player.Update(directionCode);
			}
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::A && player.IsCasting())
			{
				int directionCode = 3;//LEFT
				player.Update(directionCode);
			}
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::D && player.IsCasting())
			{
				int directionCode = 4;//RIGHT
				player.Update(directionCode);
			}
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Mouse::Left && player.IsFireBallInHand())
			{
				auto fireballTarget = sf::Mouse::getPosition(window);
				player.CastFireBall(fireballTarget);
			}
		}

		//Game logic
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && !player.IsCasting() && !player.IsFireBallInHand())
		{
			player.SetIsCastingTrue();
		}

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && player.IsCasting() || player.IsFireBallInHand() && player.IsCasting())
		{
			player.SetIsCastingFalse();
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

		//Update GUI draw values

		gui.UpdateFpsText(1 / frame_time.asSeconds());
		gui.UpdateFireBallGUIPosition(player);
		
		player.UpdateFireballs(frame_time.asSeconds()); // Update player state, including fireball combo

		// Clear window
		window.clear(sf::Color::Black);

		// Draw everything
		window.draw(player.GetSprite());
		window.draw(gui.GetFpsText());

		if (player.IsFireBallInHand())
		{
		window.draw(gui.fireballOne);
		window.draw(gui.fireballTwo);
		window.draw(gui.fireballThree);
		}

		for (const auto& fireball : player.GetActiveFireballs())
		{
			window.draw(fireball.shape);
		}

		// Display the draw buffer
		window.display();
	}

	return 0;
}
