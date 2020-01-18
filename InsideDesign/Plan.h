#pragma once
class Plan
{
	sf::Texture backgroundTexture;
	sf::Sprite background;
	std::vector<Element*> elements;
	sf::RenderWindow window = { sf::VideoMode(1280, 800), "InsideDesign" };
	Menu menu = {window};
public:
	enum Types {CHAIR, TABLE, PLANT};
	Plan();
	void run();
	void addElement(Plan::Types type);
	void render();
	bool moveElementOnMouseHover(sf::Event & event);
	void ElementOnMouseHoverBorder();
	~Plan();
};

