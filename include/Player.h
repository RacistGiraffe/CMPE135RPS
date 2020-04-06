#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	void setplayerselection(int x);
	static unsigned int getplayerselection();
private:
	static unsigned int playerselection;
};

#endif
