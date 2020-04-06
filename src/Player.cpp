#include <iostream>
#include "../include/Player.h"
using namespace std;

void Player::setplayerselection(int x) {
	playerselection = x;
}

unsigned int Player::getplayerselection() {
	return playerselection;
}
