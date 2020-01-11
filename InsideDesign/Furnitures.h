#pragma once
#include "pch.h"
#include "Furnitures.h"

class Chair : public Element {
public:
	Chair() {};
	Chair(sf::RenderWindow & window);
};

class Plant : public Element {
public:
	Plant() {};
	Plant(sf::RenderWindow & window);
};

class Table : public Element {
public:
	Table() {};
	Table(sf::RenderWindow & window);
};