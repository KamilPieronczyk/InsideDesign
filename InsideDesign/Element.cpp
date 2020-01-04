#include "pch.h"
#include "Element.h"


Element::Element(sf::RenderWindow & window)
{
	this->window = &window;
}


Element::~Element()
{
}

void Element::setTexture(std::string filename)
{
	shape.setFillColor(sf::Color::Red);
}

void Element::setSize(int width, int height)
{
	this->shape.setSize(sf::Vector2f(width, height));
}

bool Element::moveOnMouseHover(sf::Event & event)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (
			sf::Mouse::getPosition(*window).x - shape.getPosition().x < this->shape.getSize().x
			&& sf::Mouse::getPosition(*window).x - shape.getPosition().x > 0
			&& sf::Mouse::getPosition(*window).y - shape.getPosition().y < this->shape.getSize().y
			&& sf::Mouse::getPosition(*window).y - shape.getPosition().y > 0
			) {
			this->isMouseHover = true;
		}
	}
	if (event.type == sf::Event::EventType::MouseMoved && isMouseHover) {
		move(sf::Vector2f(event.mouseMove.x - shape.getPosition().x, event.mouseMove.y - shape.getPosition().y));
		return true;
	}
	if (event.type == sf::Event::EventType::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		this->isMouseHover = false;
	}
	return false;
}
