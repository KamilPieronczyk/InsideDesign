#include "pch.h"
#include "Plan.h"


void Plan::run()
{
	sf::err().rdbuf(NULL);
	sf::Event event;

	while (window.isOpen())
	{
		window.clear();
		window.draw(this->background);
		menu.draw();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (moveElementOnMouseHover(event)) break;
			ElementOnMouseHoverBorder();
			onRightClick(event);
			menu.chair.onClick(event, [this] {addElement(Plan::CHAIR, menu.chair.textureIndex); });
			menu.table.onClick(event, [this] {addElement(Plan::TABLE); });
			menu.plant.onClick(event, [this] {addElement(Plan::PLANT, menu.plant.textureIndex); });
			menu.chair.onRightClick(event, [this] {menu.chair.nextTexture(); });
			menu.table.onRightClick(event, [this] {std::cout << "table" << std::endl; });
			menu.plant.onRightClick(event, [this] {menu.table.nextTexture(); });
		}
		render();
		window.display();
	}
}

void Plan::addElement(Plan::Types type, int index)
{
	std::cout << "added" << std::endl;
	switch (type)
	{
	case Plan::Types::CHAIR :
		elements.push_back(new Chair(window));
		elements.back()->setTextureByIndex(--index);
		elements.back()->setPosition(50, 50);
		break;
	case Plan::Types::TABLE:
		elements.push_back(new Table(window));
		elements.back()->setPosition(150, 100);
		break;
	case Plan::Types::PLANT:
		elements.push_back(new Plant(window));
		elements.back()->setTextureByIndex(--index);
		elements.back()->setPosition(50, 50);
		break;
	}
}

void Plan::render()
{
	for (auto el : elements) {
		el->draw();
	}
}

bool Plan::moveElementOnMouseHover(sf::Event & event)
{
	for (auto el : elements) {
		if(el->moveOnMouseHover(event)) return true;
	}
	return false;
}

void Plan::onRightClick(sf::Event & event)
{
	for (auto el : elements) {
		el->onRightClick(event, [el]() {el->rotate(); });
	}
}

void Plan::ElementOnMouseHoverBorder()
{
	for (auto el : elements) {
		el->OnMouseHoverBorder();
	}
}

Plan::Plan()
{
	this->backgroundTexture.loadFromFile("background.png");
	this->background.setTexture(this->backgroundTexture);
}


Plan::~Plan()
{
}
