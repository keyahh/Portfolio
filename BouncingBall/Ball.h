#pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Ball : public sf::CircleShape
{
private:
	sf::Vector2f velocity;
	sf::Vector2u windowSize;

public:
	Ball();
	Ball(const sf::Vector2f& windowSize);
	Ball(const sf::Vector2f& windowSize, const sf::Vector2f& startPos);
	Ball(const sf::Vector2f& velocity, const sf::Vector2f& windowSize, const sf::Color& color, float size, const sf::Vector2f& position);

	void setVelocity(sf::Vector2f velocity);
	void setWindowSize(sf::Vector2u& windowSize);

	const sf::Vector2f& getVelocity() const;
	const sf::Vector2u& getWindowSize() const;

	void bounce();
	void ballMain();
};

