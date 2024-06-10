#include "Ball.h"

Ball::Ball() 
	: Ball(sf::Vector2f(1.0f, 1.0f), sf::Vector2f(1200, 800 ))
{
	//Ball::velocity = { float(rand() % 15 - 7), float(rand() % 15 - 7 )};
}

Ball::Ball(const sf::Vector2f& windowSize)
	: Ball(sf::Vector2f( float(rand() % 30 + 20), float(rand() % 30 + 10) ), windowSize, sf::Color::Red, 40, {100, 100})
{
	sf::CircleShape::setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256 ));
	//Ball::velocity = { float(rand() % 80 + 60), float(rand() % 80 + 60) };
}

Ball::Ball(const sf::Vector2f& windowSize, const sf::Vector2f& startPos)
	: Ball(sf::Vector2f(float(rand() % 30 + 20), float(rand() % 30 + 10)), windowSize, sf::Color::Red, 40, sf::Vector2f(startPos))
{
	sf::CircleShape::setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
}


Ball::Ball(const sf::Vector2f& velocity, const sf::Vector2f& windowSize, const sf::Color& color, float radius, const sf::Vector2f& position)
	: velocity(velocity), windowSize(windowSize)
{
	sf::CircleShape::setFillColor(color);
	sf::CircleShape::setRadius(radius);
	sf::CircleShape::setPosition(position);
}

const sf::Vector2f& Ball::getVelocity() const
{
	return Ball::velocity;
}

const sf::Vector2u& Ball::getWindowSize() const
{
	return Ball::windowSize;
}

void Ball::setVelocity(sf::Vector2f velocity)
{
	Ball::velocity = velocity;
}

void Ball::setWindowSize(sf::Vector2u& windowSize)
{
	Ball::windowSize = windowSize;
}


void Ball::bounce()
{
	if (sf::CircleShape::getPosition().x <= 0 || sf::CircleShape::getPosition().x + sf::CircleShape::getGlobalBounds().width >= Ball::windowSize.x)
		Ball::velocity.x *= -1;
	if (sf::CircleShape::getPosition().y <= 0 || sf::CircleShape::getPosition().y + sf::CircleShape::getGlobalBounds().height >= Ball::windowSize.y)
		Ball::velocity.y *= -1;
}

void Ball::ballMain()
{
	bounce();
	sf::CircleShape::move(velocity);
}