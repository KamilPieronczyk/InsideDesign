#include "pch.h"
#include "Furnitures.h"

Chair::Chair(sf::RenderWindow & window)
{
	this->window = &window;
	setTexture("chair.png");
	setSize(100, 100);
}

Plant::Plant(sf::RenderWindow & window)
{
	this->window = &window;
	setTexture("plant.png");
	setSize(100, 100);
}

Table::Table(sf::RenderWindow & window)
{
	this->window = &window;
	setTexture("");
	setSize(300, 200);
}