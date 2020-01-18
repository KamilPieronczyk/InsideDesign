#include "pch.h"
#include "Menu.h"

Menu::Menu(sf::RenderWindow & window) :window(&window)
{
	chair.window = &window;
	table.window = &window;
	plant.window = &window;
	chair.setPosition(1130, 100);
	table.setPosition(1130, 300);
	plant.setPosition(1130, 480);
}
/*
void Menu::onClick(sf::Event & event, std::function<void(Plan::Types type)> callback)
{
	chair.onClick(event, [callback]() {callback(Plan::CHAIR); });
	table.onClick(event, [callback]() {callback(Plan::TABLE); });
	plant.onClick(event, [callback]() {callback(Plan::PLANT); });
}
*/
void Menu::draw()
{
	chair.draw();
	table.draw();
	plant.draw();
}

Menu::~Menu()
{
}
