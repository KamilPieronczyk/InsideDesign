#include "pch.h"
#include "Menu.h"

Menu::Menu(sf::RenderWindow & window) :window(&window)
{
	chair.window = &window;
	table.window = &window;
	plant.window = &window;
	chair.setPosition(1000, 100);
	table.setPosition(1000, 240);
	plant.setPosition(1000, 480);
}

void Menu::draw()
{
	chair.draw();
	table.draw();
	plant.draw();
}

Menu::~Menu()
{
}
