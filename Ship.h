#ifndef SHIP_H
#define SHIP_H

#include "Object.h"

class Ship : public Object {

protected:
	int firerate;
	int health;
	
public:
	Ship();
	~Ship();
	
	int getFirerate();
	int getHealth();
	
	void setFirerate(int n);
	void setHealth(int n);
};

#endif