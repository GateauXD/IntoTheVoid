#ifndef SHIP_H
#define SHIP_H

#include "Object.h"

class Ship : public Object {

protected:
	int firerate;
	int health;
	
public:
	
	int getFirerate() const { return firerate; }
	int getHealth() const { return health; }
	
	void setFirerate(int n) { firerate = n; }
	void setHealth(int n) { health = n; }
};

#endif