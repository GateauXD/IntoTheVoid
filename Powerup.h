#ifndef POWERUP_H
#define POWERUP_H

#include "Object.h"

class Powerup : public Object {
	
public:
	Powerup();
	void draw()const;
	void movePos(unsigned char key);
	
	~Powerup();
};

#endif
