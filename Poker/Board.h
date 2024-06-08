#ifndef BOARDH
#define BOARDH

#include "DisplayCard.h"
#include <vector>
#include <assert.h>
#include "TextBox.h"
#include "PokerScoreCard.h"
#include "Deck.h"
#include "CardHand.h"
#include "CardHandScorer.h"

class Board : public sf::Drawable
{
private:
	int handMatch = 0, iters = 0;
	sf::Font font;
	std::vector<DisplayCard> cardVec;
	std::vector<TextBox> handsText;
	std::vector<TextBox> oddsText;

	PokerScoreCard scoreCard;
	Deck deck;
	CardHand cardHand;

	void setBoard();
	void checkHandMatch();
	void updateScoreBoxes();
public:
	//Board();
	Board(const std::vector<DisplayCard>& cardVector = { DisplayCard(TEN, CLUBS), DisplayCard(JACK, CLUBS), DisplayCard(QUEEN, CLUBS), DisplayCard(KING, CLUBS), DisplayCard(ACE, CLUBS) });
	const std::vector<DisplayCard>& getCardVec() const;
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	void main();
	void update();
};

#endif

