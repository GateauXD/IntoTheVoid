#ifndef POWERUP_H
#define POWERUP_H

#include "Object.h"

class Powerup : public Object {
	
public:
	Powerup();
	Powerup(int x,int y);
	void draw()const;
	void movePos(unsigned char key);
	void speedup(int& x);
	~Powerup();
};

#endif
