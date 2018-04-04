#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Object.h"

class Projectile : public Object {
	int speed;
	
public:
	Projectile();
	~Projectile();
	
	int getSpeed();
};

#endif