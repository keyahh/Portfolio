#include "CalculatorProgram.h"

void CalculatorProgram::eventHandler(sf::RenderWindow& window, sf::Event event, float dt)
{
	c.eventHandler(window, event, dt);
}

void CalculatorProgram::update(float dt)
{
	c.update(dt);
}

void CalculatorProgram::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(c);
}

std::string CalculatorProgram::getTitle() const
{
	return "RPN Calculator";
}
