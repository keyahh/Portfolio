#ifndef BOUNCINGBALLPROGRAMH
#define BOUNCINGBALLPROGRAMH

#include "Program.h"
#include "BouncingBall/BouncingBall.h"

class BoucingBallProgram : public Program
{
private:
    BouncingBall bb;

public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event, float dt);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual std::string getTitle() const;
};

#endif