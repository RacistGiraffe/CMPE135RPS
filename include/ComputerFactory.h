#ifndef COMPUTERFACTORY_H
#define COMPUTERFACTORY_H

#include <iostream>
#include "../include/Computer.h"

using namespace std;

class ComputerFactory:public Computer {
public:
	static Computer *difficulty(int diff);
};

#endif
