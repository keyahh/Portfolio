#include "PokerScoreCard.h"

void PokerScoreCard::operator +=(const Scores& score)
{
	ttlScores.ROYAL_FLUSH += score.ROYAL_FLUSH;
	ttlScores.STRAIGHT_FLUSH += score.STRAIGHT_FLUSH;
	ttlScores.FOUR_OF_A_KIND += score.FOUR_OF_A_KIND;
	ttlScores.FULL_HOUSE += score.FULL_HOUSE;
	ttlScores.FLUSH += score.FLUSH;
	ttlScores.STRAIGHT += score.STRAIGHT;
	ttlScores.THREE_OF_A_KIND += score.THREE_OF_A_KIND;
	ttlScores.TWO_PAIR += score.TWO_PAIR;
	ttlScores.ONE_PAIR += score.ONE_PAIR;
	ttlScores.HIGH_HAND += score.HIGH_HAND;
}

int& PokerScoreCard::operator[](int index)
{
	switch (index)
	{
	case 0:
		return ttlScores.ROYAL_FLUSH;
		break;
	case 1:
		return ttlScores.STRAIGHT_FLUSH;
		break;
	case 2:
		return ttlScores.FOUR_OF_A_KIND;
		break;
	case 3:
		return ttlScores.FULL_HOUSE;
		break;
	case 4:
		return ttlScores.FLUSH;
		break;
	case 5:
		return ttlScores.STRAIGHT;
		break;
	case 6:
		return ttlScores.THREE_OF_A_KIND;
		break;
	case 7:
		return ttlScores.TWO_PAIR;
		break;
	case 8:
		return ttlScores.ONE_PAIR;
		break;
	case 9:
		return ttlScores.HIGH_HAND;
		break;
	}
}

void PokerScoreCard::displayScores()
{
	output("Royal Flush: " + std::to_string(ttlScores.ROYAL_FLUSH) + "\n");
	output("Straight Flush: " + std::to_string(ttlScores.STRAIGHT_FLUSH) + "\n");
	output("Four of a Kind: " + std::to_string(ttlScores.FOUR_OF_A_KIND) + "\n");
	output("Full House: " + std::to_string(ttlScores.FULL_HOUSE) + "\n");
	output("Flush: " + std::to_string(ttlScores.FLUSH) + "\n");
	output("Straight: " + std::to_string(ttlScores.STRAIGHT) + "\n");
	output("Three of a Kind: " + std::to_string(ttlScores.THREE_OF_A_KIND) + "\n");
	output("Two Pair: " + std::to_string(ttlScores.TWO_PAIR) + "\n");
	output("One Pair: " + std::to_string(ttlScores.ONE_PAIR) + "\n");
	output("High Hand: " + std::to_string(ttlScores.HIGH_HAND) + "\n");
}

const Scores& PokerScoreCard::getScores() const
{
	return PokerScoreCard::ttlScores;
}

void PokerScoreCard::output(const std::string& str)
{
	std::cout << str;
}