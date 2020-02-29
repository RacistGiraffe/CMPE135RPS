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
	unsigned int check;
	for (int i = 0; i < 20; i++) {
		cout << "Game #" << i + 1 << endl;
		player.setplayerselection();
		computer.setcomputerselection();
		check = gameresult(player.getplayerselection(),
				computer.getcomputerselection());
		if (check == 1)
			i--;
		else if (check == 2){
			cout << "Something went wrong, fatal error, ending program." << endl;
			break;
		}
	}
	printscore();
}

void Game::printscore() {
	cout << "This set's total: " << endl;
	cout << "Player score: " << playerscore << endl;
	cout << "Computer score: " << computerscore << endl;
	cout << "Tie score: " << tiescore << endl;
}

unsigned int Game::gameresult(unsigned int x, unsigned int y) {
	if (x == y) {
		cout << "Game was a tie" << endl << endl;
		tiescore++;
		return 0;
	} else if (x == 1) {
		if (y == 2) {
			cout << "Game was lost" << endl << endl;
			computerscore++;
			return 0;
		} else if (y == 3) {
			cout << "Game was won" << endl << endl;
			playerscore++;
			return 0;
		}
	} else if (x == 2) {
		if (y == 1) {
			cout << "Game was won" << endl << endl;
			playerscore++;
			return 0;
		} else if (y == 3) {
			cout << "Game was lost" << endl << endl;
			computerscore++;
			return 0;
		}
	} else if (x == 3) {
		if (y == 1) {
			cout << "Game was lost" << endl << endl;
			computerscore++;
			return 0;
		} else if (y == 2) {
			cout << "Game was won" << endl << endl;
			playerscore++;
			return 0;
		}
	} else {
		cout << "Invalid input, please enter a valid input" << endl << endl;
		return 1;
	}
	return 2;
}
