#ifndef GAME_H
#define GAME_H

class Game
{
public:
	void play();

private:
	unsigned int playerscore = 0;
	unsigned int computerscore = 0;
	unsigned int tiescore = 0;
	void printscore();
};

#endif
