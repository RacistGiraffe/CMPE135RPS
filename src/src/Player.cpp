#include <iostream>
#include "../include/Player.h"
using namespace std;

void Player::setplayerselection() {
	cout << "1. Rock \t" << "2. Paper\t" << "3. Scissors" << endl;
	cout << "Enter selection: ";
	cin >> playerselection;
}

unsigned int Player::getplayerselection() {
	return playerselection;
}
