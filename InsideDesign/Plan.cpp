#include "pch.h"
#include "Plan.h"


void Plan::run()
{
	sf::err().rdbuf(NULL);
	sf::Event event;

	Table table(window);

	while (window.isOpen())
	{
		window.clear();
		window.draw(this->background);
		menu.draw();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(table.moveOnMouseHover(event)) break;
		}
		table.draw();
		window.display();
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
