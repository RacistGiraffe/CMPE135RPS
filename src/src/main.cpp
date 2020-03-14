#include <iostream>
#include "../include/Game.h"
#include "../include/Computer.h"
using namespace std;

/*
 * TODO:
 * Add difficulty of computer (in the next assignment) - this requires us to make constructors for it too
 * Maybe create a scoreboard class to increase cohesion
 * When more difficulties are added, make the computer class immutable
 * Maybe rename variables to be better
 * If needed, add methods to change length of game
 * Maybe make the game run from make instead of main - makes it look more like a real game
 */

//To run the game, simply build and run this file
int main() {
	Game newgame;
	newgame.play();
	return 0;
}
