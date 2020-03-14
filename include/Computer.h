#ifndef COMPUTER_H
#define COMPUTER_H

class Computer {
public:
	virtual void setcomputerselection() = 0;
	unsigned int getcomputerselection();


protected:
	unsigned int computerselection;
};

#endif
