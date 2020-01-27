#pragma once
class Element
{
public:
	sf::Texture image;
	sf::RectangleShape shape;
	sf::RenderWindow * window;
	bool isMouseHover = false;
	std::vector<sf::Texture> images;
	int textureIndex = 0;
	sf::Time lastClick; 
	sf::Clock clock;
public:
	Element() { };
	Element(sf::RenderWindow & window);
	~Element();
	void inline move(sf::Vector2f vector) { this->shape.move(vector); };
	bool isMouseOver();
	void setTexture(std::string filename);
	void loadTextures(std::vector<std::string> filenames);
	void nextTexture();
	void setTextureByIndex(int i);
	void setSize(int width, int height);
	void setPosition(int x, int y) { this->shape.setPosition((float)x, (float)y); };
	void rotate();
	bool moveOnMouseHover(sf::Event & event);
	bool onClick(sf::Event & event);
	void onClick(sf::Event & event, std::function<void(void)> callback);
	void onFastClick(sf::Event & event, std::function<void(void)> callback);
	void onRightClick(sf::Event & event, std::function<void(void)> callback);
	void OnMouseHoverBorder();
	void inline draw() { (*window).draw(shape); }
};

