#include "Portfolio.h"
#include "GridProgram.h"

int main()
{
	Portfolio p;

	GridProgram gridProgram;
	p.addProgram(gridProgram);

	p.run();

	return 0;
}

