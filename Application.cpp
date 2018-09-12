#include <SFML/Graphics.hpp>
#include <iostream>

#include "Application.h"

Application::Application(const std::string &title, unsigned int width, unsigned int height) :
	window({width, height}, title, sf::Style::Close | sf::Style::Titlebar)
{
}

Application::~Application()
{
}

void Application::poll_events(sf::Event &event)
{
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Application::clear_screen()
{
	window.display();
	window.clear(sf::Color::Black);
}

sf::RenderWindow& Application::get_window()
{
	return window;
}
