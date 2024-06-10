#ifndef BOARDH
#define BOARDH

#include "../Helper/Fonts.h"
#include "DisplayCard.h"
#include "ScoreBox.h"
#include "PokerScoreCard.h"
#include "Deck.h"
#include "CardHand.h"
#include "CardHandScorer.h"
#include <vector>

class Board : public sf::Drawable
{
private:
	int handMatch = 0, iters = 0;
	std::vector<DisplayCard> cardVec;
	std::vector<ScoreBox> handsText;
	std::vector<ScoreBox> oddsText;

	PokerScoreCard scoreCard;
	Deck deck;
	CardHand cardHand;

	void setBoard();
	void checkHandMatch();
	void updateScoreBoxes();
public:
	Board();
	Board(const std::vector<DisplayCard>& cardVector);
	const std::vector<DisplayCard>& getCardVec() const;
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	void update();
	void create(const std::vector<DisplayCard>& cardVector);
};

#endif

