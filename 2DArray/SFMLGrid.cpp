#include "SFMLGrid.h"

SFMLGrid::SFMLGrid()
	: rows(3), cols(3)
{
	createArray();
	fillArray();
}

SFMLGrid::SFMLGrid(const SFMLGrid& grid)
{
	*this = grid;
}

void SFMLGrid::createArray()
{
	array = new sf::RectangleShape * [cols];
	for (int i = 0; i < cols; i++)
	{
		*(array + i) = new sf::RectangleShape[rows];
	}
}

void SFMLGrid::fillArray()
{
	sf::Vector2f pos = { 10.0f, 10.0f };
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			*(*(array + i) + j) = setRectangle(pos);
			pos.x += 60.0f;
		}
		pos.y += 60.0f;
		pos.x = 10.0f;
	}
}

sf::RectangleShape SFMLGrid::setRectangle(const sf::Vector2f& pos)
{
	sf::RectangleShape newRect({ 50.0f, 50.0f });
	newRect.setFillColor(sf::Color::White);
	newRect.setPosition(pos);
	return newRect;
}

void SFMLGrid::resize(int row, int col)
{
	//this -> ~SFMLGrid(); program will crash at window.display() if i use destructor instead
	this -> deleteArray();

	rows = row;
	cols = col;
	createArray();
	fillArray();
}



void SFMLGrid::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			window.draw(*(*(array + i) + j));
		}
	}
}

void SFMLGrid::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		resize(rows + 1, cols + 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (rows > 1 && cols > 1) 
		{
			resize(rows - 1, cols - 1);
		}
	}
}

void SFMLGrid::operator=(const SFMLGrid& grid)
{
	if (this == &grid)
		return;

	this->rows = grid.rows;
	this->cols = grid.cols;

	this -> ~SFMLGrid();
	createArray();
	fillArray();
}


void SFMLGrid::deleteArray()
{
	for (int i = 0; i < cols; i++) {
		delete[] * (array + i);
	}
	delete[]array;
}

SFMLGrid::~SFMLGrid()
{
	this->deleteArray();
}