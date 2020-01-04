#include "pch.h"
#include "Furnitures.h"

Chair::Chair(sf::RenderWindow & window)
{
	this->window = &window;
	setTexture("");
	setSize(100, 100);
}

void Chair::setTexture(std::string filename)
{
	this->shape.setFillColor(sf::Color::Blue);
}

Plant::Plant(sf::RenderWindow & window)
{
	this->window = &window;
	setTexture("");
	setSize(100, 100);
}

void Plant::setTexture(std::string filename)
{
	this->shape.setFillColor(sf::Color::Green);
}

Table::Table(sf::RenderWindow & window)
{
	this->window = &window;
	setTexture("");
	setSize(300, 200);
}

void Table::setTexture(std::string filename)
{
	this->shape.setFillColor(sf::Color::Yellow);
}
