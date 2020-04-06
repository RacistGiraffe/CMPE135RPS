#include "../include/History.h"
#include <iostream>
using namespace std;

int *History::gethistory() {
	return history;
}

void History::addhistory(int index, int value) {
	history[index] = value;
}

void History::updatehistory(int x, int y) {
	history[0] = history[2];
	history[1] = history[3];
	history[2] = history[4];
	history[3] = y;
	history[4] = x;
}
