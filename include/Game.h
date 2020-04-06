#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Computer.h"
#include "ComputerFactory.h"
#include "History.h"

class Game {
public:
	void play();
	Player player;
	History history;
	Computer *computer = ComputerFactory::difficulty(2);
	unsigned int gameresult(unsigned int x, unsigned int y);


private:
	unsigned int playerscore = 0;
	unsigned int computerscore = 0;
	unsigned int tiescore = 0;
	unsigned int roundcount = 0;
	void printscore();
};

#endif
