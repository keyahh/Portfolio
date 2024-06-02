#ifndef BOUNCINGBALLH
#define BOUNCINGBALLH

#include "Ball.h"
#include <vector>

class BouncingBall : public sf::Drawable
{
private:
	std::vector<Ball> balls;
	sf::Vector2u windowSize;
	int padding;

public:
	BouncingBall(const sf::Vector2u& windowSize = { 1920, 1080 }, int padding = 100);
	void update();
	void eventHandler(sf::RenderWindow& window, sf::Event& event);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif