
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


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
	sf::RenderWindow window(sf::VideoMode(800, 600), "animated fsm");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	int timer = 0;

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
	Climb.addFrame(sf::IntRect(3, 428, 84, 84));
	Climb.addFrame(sf::IntRect(88, 428, 84, 84));
	Climb.addFrame(sf::IntRect(173, 428, 84, 84));
	Climb.addFrame(sf::IntRect(258, 428, 84, 84));
	Climb.addFrame(sf::IntRect(343, 428, 84, 84));
	Climb.addFrame(sf::IntRect(428, 428, 84, 84));

	AnimatedSprite Sword(texture);
	Sword.addFrame(sf::IntRect(3, 88, 84, 84));
	Sword.addFrame(sf::IntRect(88, 88, 84, 84));
	Sword.addFrame(sf::IntRect(173, 88, 84, 84));
	Sword.addFrame(sf::IntRect(258, 88, 84, 84));
	Sword.addFrame(sf::IntRect(343, 88, 84, 84));
	Sword.addFrame(sf::IntRect(428, 88, 84, 84));

	AnimatedSprite Hammer(texture);
	Hammer.addFrame(sf::IntRect(3, 343, 84, 84));
	Hammer.addFrame(sf::IntRect(88, 343, 84, 84));
	Hammer.addFrame(sf::IntRect(173, 343, 84, 84));
	Hammer.addFrame(sf::IntRect(258, 343, 84, 84));
	Hammer.addFrame(sf::IntRect(343, 343, 84, 84));
	Hammer.addFrame(sf::IntRect(428, 343, 84, 84));

	AnimatedSprite Shovel(texture);
	Shovel.addFrame(sf::IntRect(3, 515, 84, 84));
	Shovel.addFrame(sf::IntRect(88, 515, 84, 84));
	Shovel.addFrame(sf::IntRect(173, 515, 84, 84));
	Shovel.addFrame(sf::IntRect(258, 515, 84, 84));
	Shovel.addFrame(sf::IntRect(343, 515, 84, 84));
	Shovel.addFrame(sf::IntRect(428, 515, 84, 84));

	AnimatedSprite Walk(texture);
	Walk.addFrame(sf::IntRect(3, 173, 84, 84));
	Walk.addFrame(sf::IntRect(88, 173, 84, 84));
	Walk.addFrame(sf::IntRect(173, 173, 84, 84));
	Walk.addFrame(sf::IntRect(258, 173, 84, 84));
	Walk.addFrame(sf::IntRect(343, 173, 84, 84));
	Walk.addFrame(sf::IntRect(428, 173, 84, 84));

	// Setup the Player
	Player player(Idle, Jump, Climb, Sword, Hammer, Shovel ,Walk);
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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
				{
					input.setCurrent(Input::Action::JUMP);
					timer = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
				{
					input.setCurrent(Input::Action::HAMMER);
					timer = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
				{
					input.setCurrent(Input::Action::CLIMB);
					timer = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
				{
					input.setCurrent(Input::Action::SWORD);
					timer = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
				{
					input.setCurrent(Input::Action::SHOVEL);
					timer = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6))
				{
					input.setCurrent(Input::Action::WALK);
					timer = 0;
				}
				break;
			default:
				break;
			}
		}

		if (input.getCurrent() != Input::Action::IDLE)
		{
			timer++;
		}

		if (timer >= 3600)
		{
			input.setCurrent(Input::Action::IDLE);
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