#pragma once
#include "pch.h"
#include "Furnitures.h"

class Chair : public Element {
public:
	Chair() {};
	Chair(sf::RenderWindow & window);
	void setTexture(std::string filename);
};

class Plant : public Element {
public:
	Plant() {};
	Plant(sf::RenderWindow & window);
	void setTexture(std::string filename);
};

class Table : public Element {
public:
	Table() {};
	Table(sf::RenderWindow & window);
	void setTexture(std::string filename);
};