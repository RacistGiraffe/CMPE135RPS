#include <iostream>
#include "../include/Player.h"
using namespace std;

void Player::setplayerselection(int x) {
	//cout << "1. Rock \t" << "2. Paper\t" << "3. Scissors" << endl;
	//cout << "Enter selection: ";
	//cin >> playerselection;
	playerselection = x;
}

unsigned int Player::getplayerselection() {
	return playerselection;
}
