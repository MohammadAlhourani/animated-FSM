#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite idle
	AnimatedSprite Idle(texture);
	Idle.addFrame(sf::IntRect(3, 3, 84, 84));
	Idle.addFrame(sf::IntRect(88, 3, 84, 84));
	Idle.addFrame(sf::IntRect(173, 3, 84, 84));
	Idle.addFrame(sf::IntRect(258, 3, 84, 84));
	Idle.addFrame(sf::IntRect(343, 3, 84, 84));
	Idle.addFrame(sf::IntRect(428, 3, 84, 84));

	AnimatedSprite Jump(texture);
	Jump.addFrame(sf::IntRect(3, 259, 84, 84));
	Jump.addFrame(sf::IntRect(88, 259, 84, 84));
	Jump.addFrame(sf::IntRect(173, 259, 84, 84));
	Jump.addFrame(sf::IntRect(258, 259, 84, 84));
	Jump.addFrame(sf::IntRect(343, 259, 84, 84));
	Jump.addFrame(sf::IntRect(428, 259, 84, 84));

	AnimatedSprite Climb(texture);
	Climb.addFrame(sf::IntRect(3, 435, 84, 84));
	Climb.addFrame(sf::IntRect(88, 435, 84, 84));
	Climb.addFrame(sf::IntRect(173, 435, 84, 84));
	Climb.addFrame(sf::IntRect(258, 435, 84, 84));
	Climb.addFrame(sf::IntRect(343, 435, 84, 84));
	Climb.addFrame(sf::IntRect(428, 435, 84, 84));

	AnimatedSprite Sword(texture);
	Sword.addFrame(sf::IntRect(3, 87, 84, 84));
	Sword.addFrame(sf::IntRect(88, 87, 84, 84));
	Sword.addFrame(sf::IntRect(173, 87, 84, 84));
	Sword.addFrame(sf::IntRect(258, 87, 84, 84));
	Sword.addFrame(sf::IntRect(343, 87, 84, 84));
	Sword.addFrame(sf::IntRect(428, 87, 84, 84));

	// Setup the Player
	Player player(Idle, Jump, Climb,Sword);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					input.setCurrent(Input::Action::LEFT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					input.setCurrent(Input::Action::RIGHT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					input.setCurrent(Input::Action::UP);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					input.setCurrent(Input::Action::SWORD);
				}
				break;
			default:
				input.setCurrent(Input::Action::IDLE);
				break;
			}
		}

		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};