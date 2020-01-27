#include "pch.h"
#include "Furnitures.h"

Chair::Chair(sf::RenderWindow & window)
{
	this->window = &window;
	loadTextures({ "chair-g.png","chair-b.png","chair-p.png" ,"chair-pu.png","chair-y.png" });
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
	loadTextures({ "table-1.png","table-2.png" ,"table-3.png" });
	nextTexture();
	setSize(300, 200);
	this->shape.setOrigin(150, 100);

}