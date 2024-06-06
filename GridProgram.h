#ifndef GRIDPROGRAMH
#define GRIDPROGRAMH

#include "Grid/SFMLGrid.h"
#include "Program.h"

class GridProgram : public Program
{
private:
    SFMLGrid grid;

public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual std::string getTitle() const;
};

#endif