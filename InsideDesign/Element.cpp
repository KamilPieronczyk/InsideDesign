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
	if (!image.loadFromFile(filename))
		shape.setFillColor(sf::Color::Red);
	else
		shape.setTexture(&image);
}

void Element::loadTextures(std::vector<std::string> filenames)
{
	for (auto file : filenames) {
		images.push_back(sf::Texture());
		images.back().loadFromFile(file);
	}
}

void Element::nextTexture()
{
	shape.setTexture(&images[textureIndex++ % images.size()]);
}

void Element::setTextureByIndex(int i)
{
	shape.setTexture(&images[i % images.size()]);
}

void Element::setSize(int width, int height)
{
	this->shape.setSize(sf::Vector2f(width, height));
}

void Element::rotate()
{
	shape.rotate(90);
}

bool Element::moveOnMouseHover(sf::Event & event)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (
			this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x < this->shape.getSize().x
			&& this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x > 0
			&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y < this->shape.getSize().y
			&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y > 0
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

bool Element::onClick(sf::Event & event)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (
			this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x < this->shape.getSize().x
			&& this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x > 0
			&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y < this->shape.getSize().y
			&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y > 0
			) {
			return true;
		}
	}
	return false;
}

void Element::onClick(sf::Event & event, std::function<void(void)> callback)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (
			this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x < this->shape.getSize().x
			&& this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x > 0
			&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y < this->shape.getSize().y
			&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y > 0
			) {
			callback();
		}
	}
}

void Element::onRightClick(sf::Event & event, std::function<void(void)> callback)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
		if (
			this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x < this->shape.getSize().x
			&& this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x > 0
			&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y < this->shape.getSize().y
			&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y > 0
			) {
				callback();
		}
	}
}

void Element::OnMouseHoverBorder()
{
	if (
		this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x < this->shape.getSize().x
		&& this->shape.getOrigin().x + sf::Mouse::getPosition(*window).x - shape.getPosition().x > 0
		&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y < this->shape.getSize().y
		&& this->shape.getOrigin().y + sf::Mouse::getPosition(*window).y - shape.getPosition().y > 0
		) {
		shape.setOutlineColor(sf::Color::Blue);
		shape.setOutlineThickness(5);
	}
	else {
		shape.setOutlineThickness(0);
	}
}
