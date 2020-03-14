#ifndef GAME_H
#define GAME_H

class Game {
public:
	void play();

private:
	unsigned int playerscore = 0;
	unsigned int computerscore = 0;
	unsigned int tiescore = 0;
	unsigned int roundcount = 0;
	void printscore();
	unsigned int gameresult(unsigned int x, unsigned int y);
};

#endif
