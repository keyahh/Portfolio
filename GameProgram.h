#ifndef GAMEPROGRAM
#define GAMEPROGRAM

#include "Program.h"
#include "Game/game.h"

class GameProgram : public Program
{
private:
    Game game;
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual std::string getTitle() const;
};

#endif