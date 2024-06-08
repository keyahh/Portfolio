#ifndef CARDHAND
#define CARDHAND

#include <vector>
#include "Card.h"
#include "Deck.h"

class CardHand
{
private:
	std::vector<Card> cardHand;
	void output(const Card& output);

public:
	CardHand();
	CardHand(std::vector<Card> cardHand);

	const std::vector<Card>& getHand() const;
	void setHand(const std::vector<Card>& cardHand);

	void drawCard(Deck& deck);
	void drawHand(Deck& deck);
	void clearHand();
	void displayHand();

	int findRankCount(Ranks rank) const;
	int findSuitCount(Suits suit) const;

	const int size() const;

	const Card& operator [](int index) const;
};

#endif