#ifndef DECK
#define DECK

#include <vector>
#include <cstdlib>
#include <ctime>
#include "Card.h"

class Deck
{
private:
	std::vector<Card> cards;

	void swapCardPos(Card& c1, Card& c2);
	void output(const Card& card);

public:
	Deck();

	void shuffle();
	void displayDeck();
	void resetDeck();

	Card dealCard();
	std::vector<Card> dealHand();

	friend bool operator<(const Deck& deck, int n);
};

#endif