#ifndef POKERPROGRAMH
#define POKERPROGRAMH

#include "Program.h"
#include "Poker/Board.h"

class PokerProgram : public Program
{

private:
    inline static std::vector<DisplayCard> royalFlush = { DisplayCard(TEN, CLUBS), DisplayCard(JACK, CLUBS), DisplayCard(QUEEN, CLUBS), DisplayCard(KING, CLUBS), DisplayCard(ACE, CLUBS) };
	Board board;

public:
    PokerProgram();
    PokerProgram(const std::vector<DisplayCard>& hand);
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual std::string getTitle() const;
};

#endif