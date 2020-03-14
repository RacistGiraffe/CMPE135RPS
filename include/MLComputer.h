#ifndef MLCOMPUTER_H
#define MLCOMPUTER_H

#include <iostream>
#include "Computer.h"
#include "History.h"

using namespace std;

class MLComputer: public Computer {
public:
	void setcomputerselection();

private:
	History history;
	int record[5];
};

#endif
