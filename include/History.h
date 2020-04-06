#ifndef HISTORY_H
#define HISTORY_H

class History {
public:
	int *gethistory();
	void updatehistory(int x, int y);
	void addhistory(int index, int value);
	int get_predicted();

private:
	int history[5] = {0};
};

#endif
