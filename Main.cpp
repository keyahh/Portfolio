#include "Portfolio.h"
#include "BoucingBallProgram.h"
#include "GridProgram.h"
#include "CalculatorProgram.h"

int main()
{
	Portfolio p;

	BoucingBallProgram bbp;
	GridProgram gp;
	CalculatorProgram c;

	p.addProgram(bbp);
	p.addProgram(gp);
	p.addProgram(c);

	p.run();

	return 0;
}

