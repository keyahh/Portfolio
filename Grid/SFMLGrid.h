#ifndef SFMLGRID
#define SFMLGRID

#include "SFML/Graphics.hpp"
#include <iostream>

class SFMLGrid : public sf::Drawable
{
private:
	sf::RectangleShape** array = nullptr;
	int rows, cols;

	void createArray();
	void fillArray();
	sf::RectangleShape setRectangle(const sf::Vector2f& pos);
	void resize(int row, int col);
	void deleteArray();

public:
	SFMLGrid();
	SFMLGrid(const SFMLGrid& grid);

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	void eventHandler(sf::RenderWindow& window, sf::Event& event);

	void operator=(const SFMLGrid& grid);
	~SFMLGrid();
};

#endif

