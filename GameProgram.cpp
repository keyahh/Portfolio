#include "GameProgram.h"

void GameProgram::eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad)
{
	game.eventHandler(window, event, dt, pad);
}

void GameProgram::update(float dt)
{
	game.update(dt);
}

void GameProgram::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(game);
}

std::string GameProgram::getTitle() const
{
	return "Asteroids";
}
