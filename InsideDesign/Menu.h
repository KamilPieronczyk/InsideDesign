#pragma once
class Plan;
class Menu
{
	sf::RenderWindow * window;
public:
	Chair chair = { *window };
	Table table = { *window };
	Plant plant = { *window };
	Menu(sf::RenderWindow & window);
	//void onClick(sf::Event & event, std::function<void(Plan::Types type)>);
	void draw();
	~Menu();
};

