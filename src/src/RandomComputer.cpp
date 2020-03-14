#include <iostream>
#include "../include/Computer.h"
#include "../include/RandomComputer.h"
using namespace std;

void RandomComputer::setcomputerselection() {
	computerselection = (rand() % 3) + 1;
}
