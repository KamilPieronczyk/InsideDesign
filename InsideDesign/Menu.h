#pragma once
class Menu
{
	sf::RenderWindow * window;
	Chair chair = { *window };
	Table table = { *window };
	Plant plant = { *window };
public:
	Menu(sf::RenderWindow & window);
	void draw();
	~Menu();
};

