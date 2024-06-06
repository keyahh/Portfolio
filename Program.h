#ifndef PROGRAMH
#define PROGRAMH

#include "SFML/Graphics.hpp"

class Program : public sf::Drawable
{
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual std::string getTitle() const = 0;
};

#endif