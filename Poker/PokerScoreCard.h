#ifndef POKERSCORECARD
#define POKERSCORECARD

#include <vector>
#include <iostream>
#include <string>
#include "Scores.h"

class PokerScoreCard
{
private:
	Scores ttlScores;
	void output(const std::string& str);

public:

	void operator +=(const Scores& score);
	int& operator [](int index);
	void displayScores();
	const Scores& getScores() const;
};

#endif