#ifndef SHIP_H
#define SHIP_H

#include "Object.h"

class Ship : public Object {

protected:
	int firerate;
	int health;
	
public:
	
	int getFirerate() { return firerate; }
	int getHealth() { return health; }
	
	void setFirerate(int n) { firerate = n; }
	void setHealth(int n) { health = n; }
};

#endif