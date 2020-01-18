#include "pch.h"
#include "Furnitures.h"

Chair::Chair(sf::RenderWindow & window)
{
	this->window = &window;
	loadTextures({ "chair.png","chair-b.png" });
	nextTexture();
	//setTexture("chair.png");
	setSize(100, 100);
	this->shape.setOrigin(50, 50);
}

Plant::Plant(sf::RenderWindow & window)
{
	this->window = &window;
	loadTextures({ "plant.png" });
	nextTexture();
	setSize(100, 100);
	this->shape.setOrigin(50, 50);

}

Table::Table(sf::RenderWindow & window)
{
	this->window = &window;
	setTexture("");
	setSize(300, 200);
	this->shape.setOrigin(150, 100);

}