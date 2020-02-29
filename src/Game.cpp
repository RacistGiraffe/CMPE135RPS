#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <ctime>
#include "../include/Game.h"
#include "../include/Player.h"
#include "../include/Computer.h"
using namespace std;

void Game::play() {
	srand((unsigned) time(0));
	Player player;
	Computer computer;
	unsigned int x, y;
	unsigned int wincount = 0;
	for (int i = 0; i < 20; i++) {
		cout << "Game #" << i + 1 << endl;
		player.setplayerselection();
		computer.setcomputerselection();
		x = player.getplayerselection();
		y = computer.getcomputerselection();

		if (x == y) {
			cout << "Game was a tie" << endl;
			tiescore++;
		} else if (x == 1 && y == 2) {
			cout << "Game was lost" << endl;
			computerscore++;
		} else if (x == 1 && y == 3) {
			cout << "Game was won" << endl;
			playerscore++;
		} else if (x == 2 && y == 1) {
			cout << "Game was won" << endl;
			playerscore++;
		} else if (x == 2 && y == 3) {
			cout << "Game was lost" << endl;
			computerscore++;
		} else if (x == 3 && y == 1) {
			cout << "Game was lost" << endl;
			computerscore++;
		} else if (x == 3 && y == 2) {
			cout << "Game was won" << endl;
			wincount++;
		} else {
			cout << "Invalid input, please enter a valid input" << endl;
			i--;
		}
		cout << endl;
	}
	printscore();
}

void Game::printscore() {
	cout << "This set's total: " << endl;
	cout << "Player score: " << playerscore << endl;
	cout << "Computer score: " << computerscore << endl;
	cout << "Tie score: " << tiescore << endl;
}
