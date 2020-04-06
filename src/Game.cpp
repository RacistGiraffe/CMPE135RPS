#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <ctime>
#include "../include/Game.h"
#include "../include/Player.h"
#include "../include/Computer.h"
#include "../include/ComputerFactory.h"
#include "../include/History.h"

using namespace std;

void Game::play() {
	srand((unsigned) time(0));
	int botdiff;
	unsigned int check;

	cout << "1. Start Game \t" << "2. Change round count \t" << "3. Exit" << endl;
	cin >> check;
	if(check == 2) {
		cout << "Please enter the new number of rounds: ";
		cin >> round_count;
	}

	else if (check == 3)
		return;

	cout << "1. Easy \t" << "2. Hard" << endl;
	cout << "Please select computer difficulty: ";
	cin >> botdiff;


	for (int i = 0; i < round_count; i++) {
		cout << "Game #" << i + 1 << endl;
		//player.setplayerselection();
		computer->setcomputerselection();
		check = gameresult(player.getplayerselection(),
				computer->getcomputerselection());
		if (check == 1)
			i--;
		else if (check == 2) {
			cout << "Something went wrong, fatal error, ending program."
					<< endl;
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

unsigned int Game::get_round() {
	return round_count;
}

unsigned int Game::update_round(int x) {
	round_count = x;
}

unsigned int Game::get_player_score(){
	return playerscore;
}
unsigned int Game::get_computer_score(){
	return computerscore;
}
unsigned int Game::get_tie_score(){
	return tiescore;
}
