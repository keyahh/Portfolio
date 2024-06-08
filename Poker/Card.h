#ifndef CARD
#define CARD

#include <iostream>
#include <string>
#include "Ranks.h"
#include "Suits.h"

class Card
{
private:
	Suits suit;
	Ranks rank;

public:
	Card();
	Card(Ranks rank, Suits suit);

	const Suits getSuit() const;
	const Ranks getRank() const;

	void setRank(Ranks rank);
	void setSuit(Suits suit);
	std::string getStrRank(const Ranks rank) const;
	std::string getStrSuit(const Suits suit) const;


	friend bool operator ==(const Card& card1, const Card& card2);
	friend std::ostream& operator <<(std::ostream& out, const Card& card);
};

#endif