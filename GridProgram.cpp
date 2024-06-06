#include "GridProgram.h"

void GridProgram::eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad)
{
	grid.eventHandler(window, event);
}

void GridProgram::update(float dt)
{
}

void GridProgram::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid);
}

std::string GridProgram::getTitle() const
{
	return "2D Array Grid";
}
