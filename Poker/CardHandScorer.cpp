#include "CardHandScorer.h"

Scores CardHandScorer::scoreHand(const CardHand& cardHand)
{
	Scores scoreCard = {0,0,0,0,0,0,0,0,0,0};
	scoreCard.HIGH_HAND++;

	//find royal flush
	if (findRoyalFlush(cardHand)) 
	{
		scoreCard.ROYAL_FLUSH++;
		scoreCard.STRAIGHT_FLUSH++;
		scoreCard.FLUSH++;
		scoreCard.STRAIGHT++;
		return scoreCard;
	}

	//find straight flush non royal
	if ((findFlush(cardHand) && findStraight(cardHand)) && cardHand.findRankCount(ACE) == 0)
	{
		scoreCard.STRAIGHT_FLUSH++;
		scoreCard.FLUSH++;
		scoreCard.STRAIGHT++;
		return scoreCard;
	}
	if (findStraight(cardHand))
	{
		scoreCard.STRAIGHT++;
		return scoreCard;
	}
	if (findFour(cardHand))
	{
		scoreCard.FOUR_OF_A_KIND++;
		scoreCard.THREE_OF_A_KIND++;
		scoreCard.TWO_PAIR++;
		scoreCard.ONE_PAIR++;
		return scoreCard;
	}
	if (findFullHouse(cardHand))
	{
		scoreCard.FULL_HOUSE++;
		scoreCard.THREE_OF_A_KIND++;
		scoreCard.TWO_PAIR++;
		scoreCard.TWO_PAIR++;
		scoreCard.ONE_PAIR++;
		return scoreCard;
	}

	if (findFlush(cardHand))
	{
		scoreCard.FLUSH++;
		return scoreCard;
	}

	if (findThree(cardHand))
	{
		scoreCard.THREE_OF_A_KIND++;
		scoreCard.ONE_PAIR++;
		return scoreCard;
	}
	
	if (findPairs(cardHand) == 2)
	{
		scoreCard.TWO_PAIR++;
		scoreCard.ONE_PAIR++;
		return scoreCard;
	}
	else
	{
		scoreCard.ONE_PAIR++;
		return scoreCard;
	}

	return scoreCard;
}

bool CardHandScorer::matchHand(const CardHand& cardHand, const std::vector<DisplayCard>& displayHand)
{
	/*for (int i = 0; i < displayHand.size(); i++)
	{
		std::cout << displayHand[i] << std::endl;
		std::cout << cardHand[i] << std::endl;
	}*/
	for (int i = 0; i < displayHand.size(); i++)
	{
		//std::cout << displayHand[i].getStrRank(displayHand[i].getRank()) << std::endl;
		if (!findMatch(cardHand, displayHand[i]))
		{
			return false;
		}
	}
	//std::cout << "hi\n";
	return true;
}

bool CardHandScorer::findRoyalFlush(const CardHand& cardHand)
{
	if ((cardHand.findRankCount(KING) >= 1 && cardHand.findRankCount(QUEEN) >= 1 && cardHand.findRankCount(JACK) >= 1 && cardHand.findRankCount(ACE) >= 1 && cardHand.findRankCount(TEN))
		&& (findFlush(cardHand)))
	{
		return true;
	}
	return false;
}

bool CardHandScorer::findFlush(const CardHand& cardHand)
{
	if (cardHand.findSuitCount(CLUBS) == 5 || cardHand.findSuitCount(DIAMONDS) == 5 ||
		cardHand.findSuitCount(HEARTS) == 5 || cardHand.findSuitCount(SPADES) == 5)
		return true;
	return false;
}

//for any variation of straights
bool CardHandScorer::findStraight(const CardHand& cardHand)
{
	const std::vector<Card> cardVec = cardHand.getHand();

	//find starting value
	Ranks lowestRank = cardVec[0].getRank();
	for (int i = 1; i < cardVec.size(); i++)
	{
		if (cardVec[i].getRank() < lowestRank)
			lowestRank = cardVec[i].getRank();
	}
	//if the lowest is ace, straight does not matter
	if (lowestRank == ACE)
		return false;
	
	Ranks nextRank = getNextRank(lowestRank);
	bool foundNext = false;
	for (int i = 0; i < cardVec.size() - 1; i++)//only has to find 4 consecutives not 5
	{
		foundNext = false;
		for (int j = 0; j < cardVec.size(); j++)
		{
			if (cardVec[j].getRank() == nextRank) {
				nextRank = getNextRank(nextRank);
				foundNext = true;
				break;
			}
		}
		if (foundNext == false)
			return false;
	}
	return true;
}

Ranks CardHandScorer::getNextRank(Ranks rank)
{
	switch (rank)
	{
	case(TWO):
		return THREE;
	case(THREE):
		return FOUR;
	case(FOUR):
		return FIVE;
	case(FIVE):
		return SIX;
	case(SIX):
		return SEVEN;
	case(SEVEN):
		return EIGHT;
	case(EIGHT):
		return NINE;
	case(NINE):
		return TEN;
	case(TEN):
		return JACK;
	case(JACK):
		return QUEEN;
	case(QUEEN):
		return KING;
	case(KING):
		return ACE;
	}
}

//returns number of distinct pairs in hand
int CardHandScorer::findPairs(const CardHand& cardHand)
{
	int pairs = 0, ttlCrds = 0, temp = 0;
	std::vector<Card> cardVec = cardHand.getHand();
	std::vector<Ranks> usedRanks;

	for (int i = 0; i < cardVec.size(); i++)
	{		
		if(!checkUsed(usedRanks, cardVec[i].getRank()))
		{
			temp = cardHand.findRankCount(cardVec[i].getRank());
			if (temp >= 2)
			{
				pairs++;
				usedRanks.push_back(cardVec[i].getRank());
			}
			ttlCrds += temp;
		}

		if (ttlCrds == 5)
			break;
	}
	return pairs;
}

bool CardHandScorer::checkUsed(const std::vector<Ranks> vec, const Ranks& rank)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == rank)
			return true;
	}
	return false;
}

bool CardHandScorer::findMatch(const CardHand& cardHand, const Card& card)
{
	for (int i = 0; i < cardHand.size(); i++)
	{
		if (card == cardHand[i])
		{
			return true;
		}
	}
	return false;
}

bool CardHandScorer::findFour(const CardHand& cardHand)
{
	for (int i = 0; i < 2; i++) //if the second card doesnt have 4 copies, automatically not a four of a kind
	{
		if (cardHand.findRankCount(cardHand.getHand()[i].getRank()) == 4)
		{
			return true;
		}
	}
	return false;
}

bool CardHandScorer::findFullHouse(const CardHand& cardHand)
{
	if (!(findPairs(cardHand) == 2))
		return false;
	for (int i = 0; i < 3; i++)
	{
		if (cardHand.findRankCount(cardHand.getHand()[i].getRank()) == 3)
			return true;
	}
	return false;
}

bool CardHandScorer::findThree(const CardHand& cardHand)
{
	for (int i = 0; i < 3; i++)
	{
		if (cardHand.findRankCount(cardHand.getHand()[i].getRank()) >= 3)
			return true;
	}
	return false;
}