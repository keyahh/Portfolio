#ifndef CARDHANDSCORER
#define CARDHANDSCORER

#include "Scores.h"
#include "CardHand.h"
#include "DisplayCard.h"

class CardHandScorer
{
private:
	static Ranks getNextRank(Ranks curRank);
	static bool findRoyalFlush(const CardHand& cardHand);
	static bool findFlush(const CardHand& cardHand);
	static bool findStraight(const CardHand& cardHand);
	static int findPairs(const CardHand& cardHand);
	static bool findFour(const CardHand& cardHand);
	static bool findFullHouse(const CardHand& cardHand);
	static bool findThree(const CardHand& cardHand);
	static bool checkUsed(const std::vector<Ranks> vec, const Ranks& rank);
	static bool findMatch(const CardHand& cardHand, const Card& card);
public:
	static Scores scoreHand(const CardHand& cardHand);
	static bool matchHand(const CardHand& cardHand, const std::vector<DisplayCard>& displayHand);
};

#endif