#include "CardHand.h"

CardHand::CardHand()
{

}

CardHand::CardHand(std::vector<Card> cardHand)
	: cardHand(cardHand)
{

}

const std::vector<Card>& CardHand::getHand() const
{
	return CardHand::cardHand;
}

void CardHand::setHand(const std::vector<Card>& cardHand)
{
	CardHand::cardHand = cardHand;
}

void CardHand::drawCard(Deck& deck)
{
	CardHand::cardHand.push_back(deck.dealCard());
}

void CardHand::drawHand(Deck& deck)
{
	CardHand::cardHand.clear();
	if (deck < 5)
		deck.resetDeck();

	setHand(deck.dealHand());
}

void CardHand::clearHand()
{
	CardHand::cardHand.clear();
}

void CardHand::displayHand()
{
	for (int i = 0; i < CardHand::cardHand.size(); i++)
	{
		std::cout << CardHand::cardHand[i] << std::endl;
	}
}

void CardHand::output(const Card& card)
{
	std::cout << card << std::endl;
}

int CardHand::findRankCount(Ranks rank) const
{
	int res = 0;
	for (int i = 0; i < CardHand::cardHand.size(); i++)
	{
		if (CardHand::cardHand[i].getRank() == rank)
			res++;
	}
	return res;
}

int CardHand::findSuitCount(Suits suit) const
{
	int res = 0;
	for (int i = 0; i < CardHand::cardHand.size(); i++)
	{
		if (CardHand::cardHand[i].getSuit() == suit)
			res++;
	}
	return res;
}

const Card& CardHand::operator [](int index) const
{
	return cardHand[index];
}

const int CardHand::size() const
{
	return cardHand.size();
}