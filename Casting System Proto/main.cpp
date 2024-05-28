#include <SFML/Graphics.hpp>
#include "Textures.hpp"
#include "Player.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "main window");
	sf::Event e;

	Textures textures;
	Player player(textures.GetPlayerTexture());

	while (window.isOpen())//once per frame
	{

		while (window.pollEvent(e))//poll events
		{
			if (e.type == sf::Event::Closed)//check for a particular event, and enact its behaviour
			{
				window.close();
			}
		}

	//Game logic


	//clear window
		window.clear(sf::Color::Black);


		//draw everything to draw buffer
		window.draw(player.GetSprite());

		//display the draw buffer
		window.display();

	}

	return 0;
}