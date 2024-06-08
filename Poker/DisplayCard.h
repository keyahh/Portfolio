#ifndef DISPLAYCARD
#define DISPLAYCARD

#include "PokerSpriteSheet.h"
#include "Card.h"

class DisplayCard : public Card, public PokerSpriteSheet
{
public:
	DisplayCard();
	DisplayCard(Ranks rank, Suits suit);
};

#endif // !DISPLAYCARD

