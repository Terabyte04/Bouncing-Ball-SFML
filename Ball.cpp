#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"

Ball::Ball(float x, float y, float radius) :
	body(radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;

	body.setOrigin(body.getRadius() / 2, body.getRadius() / 2);
	body.setPosition(x, y);

	this->x_speed = 0.1f;
	this->y_speed = 0.1f;
}

Ball::~Ball()
{
}

void Ball::update(float deltaTime)
{
	x += x_speed;
	y += y_speed;

	if (x <= 0 || x >= 640 - body.getRadius())
		x_speed *= -1;
	if (y <= 0 || y >= 480 - body.getRadius())
		y_speed *= -1;

	body.move(x_speed, y_speed);
}

void Ball::render(sf::RenderWindow &window)
{
	body.setFillColor(sf::Color::Green);
	window.draw(body);
}
