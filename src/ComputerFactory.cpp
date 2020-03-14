#include "../include/ComputerFactory.h"
#include "../include/RandomComputer.h"
#include "../include/MLComputer.h"

Computer *ComputerFactory::difficulty(int diff)
{
	if(diff == 1) {
		cout << "Creating Random Computer" << endl;
		return new RandomComputer();
	}
	else if (diff == 2) {
		cout << "Creating ML Computer" << endl;
		return new MLComputer();
	}
	else
		return NULL;
}
