#pragma once
class Menu
{
	sf::RenderWindow * window;
public:
	Chair chair = { *window };
	Table table = { *window };
	Plant plant = { *window };
	Menu(sf::RenderWindow & window);
	void draw();
	~Menu();
};

