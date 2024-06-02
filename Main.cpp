#include "Portfolio.h"
#include "BoucingBallProgram.h"
#include "GridProgram.h"

int main()
{
	Portfolio p;

	BoucingBallProgram bbp;
	GridProgram gp;
	p.addProgram(bbp);
	p.addProgram(gp);

	p.run();

	return 0;
}

