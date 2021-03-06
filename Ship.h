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
	
	//When you collect a "powerup" it will add to your speed
	void setFirerate(int n) { firerate = n; }
	void setHealth(int n) { health = n; }
	void incFirerate(int n) { firerate += n; }
	void takeHit(int hit) { health -= hit; }
};

#endif