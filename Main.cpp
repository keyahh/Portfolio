#include "Portfolio.h"
#include "BoucingBallProgram.h"
#include "GridProgram.h"
#include "PokerProgram.h"
#include "CalculatorProgram.h"

int main()
{
	std::vector<DisplayCard> royalFlush = { DisplayCard(TEN, CLUBS), DisplayCard(JACK, CLUBS), DisplayCard(QUEEN, CLUBS), DisplayCard(KING, CLUBS), DisplayCard(ACE, CLUBS) };
	Portfolio p;
	
	BoucingBallProgram bbp;
	GridProgram gp;
	CalculatorProgram c;
	PokerProgram pk(royalFlush);

	p.addProgram(bbp);
	p.addProgram(gp);
	p.addProgram(pk);
	p.addProgram(c);

	p.run();

	return 0;
}

