#include "DisplayCard.h"

DisplayCard::DisplayCard()
{
}

DisplayCard::DisplayCard(Ranks rank, Suits suit)
	: PokerSpriteSheet(), Card(rank, suit)
{
	setRowCol(suit, rank);
}
