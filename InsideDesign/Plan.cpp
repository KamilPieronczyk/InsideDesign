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
			onRightClick(event);
			ElementOnMouseHoverBorder();
			activeElement(event);
			menu.chair.onClick(event, [this] {addElement(Plan::CHAIR, menu.chair.textureIndex); });
			menu.table.onClick(event, [this] {addElement(Plan::TABLE, menu.table.textureIndex); });
			menu.plant.onClick(event, [this] {addElement(Plan::PLANT, menu.plant.textureIndex); });
			menu.chair.onRightClick(event, [this] {menu.chair.nextTexture(); });
			menu.table.onRightClick(event, [this] {menu.table.nextTexture(); });
			menu.plant.onRightClick(event, [this] {menu.plant.nextTexture(); });
			DeleteActive(event);
		}
		render();
		window.display();
	}
}

void Plan::addElement(Plan::Types type, int index)
{
	switch (type)
	{
	case Plan::Types::CHAIR :
		elements.push_back(new Chair(window));
		elements.back()->setTextureByIndex(--index);
		elements.back()->setPosition(50, 50);
		break;
	case Plan::Types::TABLE:
		elements.push_back(new Table(window));
		elements.back()->setTextureByIndex(--index);
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

void Plan::activeElement(sf::Event & event)
{
	for (auto el : elements) {
		el->onFastClick(event, [this, el] {			
			if (activedElement) {
				activedElement->shape.setOutlineThickness(0);
				activedElement->shape.setOutlineColor(sf::Color::Blue);
			}
			if (activedElement == el) {
				activedElement = nullptr;
			} else if (el != activedElement ) {			
				activedElement = el;
			}
		});
	}
	if (activedElement) {
		activedElement->shape.setOutlineColor(sf::Color::Green);
		activedElement->shape.setOutlineThickness(5);
	}
	if (event.key.code == sf::Keyboard::Add && activedElement) {
		activedElement->shape.setSize(sf::Vector2f(activedElement->shape.getSize().x + 5, activedElement->shape.getSize().y + 5));
		activedElement->shape.setOrigin(sf::Vector2f(activedElement->shape.getOrigin().x + 2.5, activedElement->shape.getOrigin().y + 2.5));
	}
	if (event.key.code == sf::Keyboard::Subtract && activedElement) {
		activedElement->shape.setSize(sf::Vector2f(activedElement->shape.getSize().x - 5, activedElement->shape.getSize().y - 5));
		activedElement->shape.setOrigin(sf::Vector2f(activedElement->shape.getOrigin().x - 2.5, activedElement->shape.getOrigin().y - 2.5));
	}
}

void Plan::DeleteActive(sf::Event & event)
{
	if (event.key.code == sf::Keyboard::Delete && activedElement) {
		int i = 0;
		for (auto el : elements) {
			if (el == activedElement) {
				elements.erase(elements.begin() + i);
				break;
			}
			i++;
		}
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
