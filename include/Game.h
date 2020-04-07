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
	unsigned int get_round_count();
	void update_round_count(int x);
	unsigned int get_player_score();
	unsigned int get_computer_score();
	unsigned int get_tie_score();
	void reset_scores();

private:
	unsigned int round_count = 0;
	unsigned int playerscore = 0;
	unsigned int computerscore = 0;
	unsigned int tiescore = 0;
	unsigned int roundcount = 20;
	void printscore();
};

#endif
