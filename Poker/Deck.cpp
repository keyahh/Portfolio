#include "Deck.h"

Deck::Deck()
{
	srand(time(0));
	resetDeck();
}

void Deck::resetDeck()
{
	Ranks ranksArr[] = {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
	Suits suitsArr[] = { CLUBS, DIAMONDS, HEARTS, SPADES };
	int temp = 0, temp1 = 0;
	for (int i = 0; i < 52; i++)
	{
		Deck::cards.push_back(Card(ranksArr[temp], suitsArr[temp1]));
		temp1++;
		if (temp1 >= 4)
		{
			temp++;
			temp1 = 0;
		}
	}
	shuffle();
}

void Deck::shuffle()
{
	for (int i = 0; i < cards.size(); i++)
	{
		swapCardPos(cards[i],cards[rand() % Deck::cards.size()]);
	}
}

void Deck::swapCardPos(Card& c1, Card& c2)
{
	Card tempCard = c1;
	c1 = c2;
	c2 = tempCard;
}

void Deck::displayDeck()
{
	for (int i = 0; i < Deck::cards.size(); i++)
	{
		output(Deck::cards[i]);
	}
}

Card Deck::dealCard()
{
	Card temp = Deck::cards[Deck::cards.size() - 1];
	Deck::cards.pop_back();
	return temp;
}

std::vector<Card> Deck::dealHand()
{
	if (Deck::cards.size() < 5)
		resetDeck();

	std::vector<Card> cardHandVec;
	for (int i = 0; i < 5; i++)
	{
		cardHandVec.push_back(dealCard());
	}

	return cardHandVec;
}

bool operator<(const Deck& deck, int n)
{
	return (deck.cards.size() < n);
}

void Deck::output(const Card& card)
{
	std::cout << card << '\n';
}