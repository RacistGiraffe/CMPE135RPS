#include "../include/MLComputer.h"
#include "../include/History.h"
#include "../include/Player.h"
#include <ctime>

unsigned int Player::playerselection;
void MLComputer::setcomputerselection()
{
	//Check if history is filled
	int *temp = {history.gethistory()};

	//Check to see if more values can be added to history first.
	for(int i = 0; i < 5; i++) {
		if(temp[i] == 0) {
			if(i == 4)
				history.addhistory(4, Player::getplayerselection());
			else {
				history.addhistory(i, Player::getplayerselection());
				computerselection = (rand() % 3) + 1;
				//Add value of player to history
				history.addhistory(++i, computerselection);
				return;
			}
		}
	}

	int rock_count = 0;
	int paper_count = 0;
	int scissors_count = 0;

	//If it gets here, history is full
	for(int i = 0; i < 5; i+=2) {
		if(temp[i] == 1)
			rock_count++;
		else if (temp[i] == 2)
			paper_count++;
		else if (temp[i] == 3)
			scissors_count++;
	}

	if(rock_count > paper_count && rock_count > scissors_count)
		computerselection = 2;
	else if (paper_count > rock_count && paper_count > scissors_count)
		computerselection = 3;
	else if (scissors_count > rock_count && scissors_count > paper_count)
		computerselection = 1;
	else{
		srand((unsigned) time(0));
		computerselection = (rand() % 3) + 1;
	}

	history.updatehistory(Player::getplayerselection(), computerselection);

}
