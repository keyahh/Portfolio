#include "BouncingBall.h"

BouncingBall::BouncingBall(const sf::Vector2u& windowSize, int padding)
    : windowSize(windowSize), padding(padding)
{
    srand(time(0));
    balls.push_back(Ball({ windowSize.x - padding * 2, windowSize.y - padding * 3 }));
}


void BouncingBall::update()
{
	for (auto& b : balls)
	{
		b.ballMain();
	}
}

void BouncingBall::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        balls.push_back(Ball({ windowSize.x - padding * 2, windowSize.y - padding * 3 }, sf::Mouse::getPosition(window)));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        for (int i = 0; i < balls.size(); i++) 
        {
            balls[i].setVelocity({ float(balls[i].getVelocity().x - 0.5), float(balls[i].getVelocity().y - 0.5) });
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        for (int i = 0; i < balls.size(); i++) 
        {
            balls[i].setVelocity({ float(balls[i].getVelocity().x + 0.5), float(balls[i].getVelocity().y + 0.5) });
        }
    }
}

void BouncingBall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& b : balls)
	{
		target.draw(b);
	}
}
