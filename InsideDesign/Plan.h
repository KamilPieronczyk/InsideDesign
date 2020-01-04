#pragma once
class Plan
{
	sf::Texture backgroundTexture;
	sf::Sprite background;
	std::vector<Element*> elements;
	sf::RenderWindow window = { sf::VideoMode(1280, 800), "InsideDesign" };
	Menu menu = {window};
public:
	Plan();
	void run();
	~Plan();
};

