#include <SFML/Graphics.hpp>
#include <iostream>

#include "Application.h"
#include "Ball.h"

static const unsigned int WIDTH  = 640;
static const unsigned int HEIGHT = 480;

int main(int argc, char *argv[])
{
	Application application("Bouncing Ball", WIDTH, HEIGHT);
	Ball ball(70.0f, 90.0f, 20.0f);

	sf::Clock clock;
	float deltaTime = 0.0f;

	while (application.get_window().isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		application.poll_events(event);
		application.clear_screen();

		ball.update(deltaTime);
		ball.render(application.get_window());
	}

	std::cin.get();
	return 0;
}