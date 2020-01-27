#pragma once
class Plan
{
	sf::Texture backgroundTexture;
	sf::Sprite background;
	std::vector<Element*> elements;
	sf::RenderWindow window = { sf::VideoMode(1280, 800), "InsideDesign" };
	Menu menu = {window};
	Element * activedElement = nullptr;
public:
	enum Types {CHAIR, TABLE, PLANT};
	Plan();
	void run();
	void addElement(Plan::Types type, int index = 0);
	void render();
	bool moveElementOnMouseHover(sf::Event & event);
	void onRightClick(sf::Event & event);
	void activeElement(sf::Event & event);
	void DeleteActive(sf::Event & event);
	void ElementOnMouseHoverBorder();
	~Plan();
};

