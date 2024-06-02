#include "BoucingBallProgram.h"

void BoucingBallProgram::eventHandler(sf::RenderWindow& window, sf::Event event, float dt)
{
    bb.eventHandler(window, event);
}

void BoucingBallProgram::update(float dt)
{
    bb.update();
}

void BoucingBallProgram::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(bb);
}

std::string BoucingBallProgram::getTitle() const
{
    return "Bouncing Ball";
}
