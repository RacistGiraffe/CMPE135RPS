#include "../include/ComputerFactory.h"
#include "../include/RandomComputer.h"
#include "../include/MLComputer.h"

Computer *ComputerFactory::difficulty(int diff)
{
	if(diff == 1)
		return new RandomComputer();
	else if (diff == 2)
		return new MLComputer();
	else
		return NULL;
}
