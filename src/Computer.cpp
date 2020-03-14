#include <iostream>
#include "../include/Computer.h"
using namespace std;

void Computer::setcomputerselection() {
	computerselection = (rand() % 3) + 1;
}

unsigned int Computer::getcomputerselection() {
	return computerselection;
}
