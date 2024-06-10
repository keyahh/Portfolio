#include "PokerProgram.h"


PokerProgram::PokerProgram()
{
	//std::vector<DisplayCard> royalFlush = { DisplayCard(TEN, CLUBS), DisplayCard(JACK, CLUBS), DisplayCard(QUEEN, CLUBS), DisplayCard(KING, CLUBS), DisplayCard(ACE, CLUBS) };
	board.create(royalFlush);
}

PokerProgram::PokerProgram(const std::vector<DisplayCard>& hand)
{
	board.create(hand);
}

void PokerProgram::eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad)
{

}

void PokerProgram::update(float dt)
{
	board.update();
}

void PokerProgram::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(board);
}

std::string PokerProgram::getTitle() const
{
	return "Poker Analysis";
}
