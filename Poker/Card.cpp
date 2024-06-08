#include "Card.h"

Card::Card()
	: Card(ACE, DIAMONDS)
{

}

Card::Card(Ranks rank, Suits suit)
	: rank(rank), suit(suit)
{

}

const Suits Card::getSuit() const
{
	return Card::suit;
}

const Ranks Card::getRank() const
{
	return Card::rank;
}

void Card::setRank(Ranks name)
{
	Card::rank = rank;
}

void Card::setSuit(Suits suit)
{
	Card::suit = suit;
}

bool operator ==(const Card& card1, const Card& card2)
{
	return (card1.getRank() == card2.getRank() && card1.getSuit() == card2.getSuit());
}

std::ostream& operator <<(std::ostream& out, const Card& card)
{
	out << card.getStrRank(card.getRank()) + " of " + card.getStrSuit(card.getSuit());
	return out;
}

std::string Card::getStrRank(const Ranks rank) const
{
	switch (rank)
	{
	case TWO:
		return "Two";
		break;
	case THREE:
		return "Three";
		break;
	case FOUR:
		return "Four";
		break;
	case FIVE:
		return "Five";
		break;
	case SIX:
		return "Six";
		break;
	case SEVEN:
		return "Seven";
		break;
	case EIGHT:
		return "Eight";
		break;
	case NINE:
		return "Nine";
		break;
	case TEN:
		return "Ten";
		break;
	case JACK:
		return "Jack";
		break;
	case QUEEN:
		return "Queen";
		break;
	case KING:
		return "King";
		break;
	case ACE:
		return "Ace";
		break;
	default:
		return "Ace";
	}
}

std::string Card::getStrSuit(const Suits suit) const
{
	switch (suit)
	{
	case CLUBS:
		return "Clubs";
		break;
	case DIAMONDS:
		return "Diamonds";
		break;
	case HEARTS:
		return "Hearts";
		break;
	case SPADES:
		return "Spades";
		break;
	default:
		return "Clubs";
	}
}