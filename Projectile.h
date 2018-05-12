#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Object.h"

class Projectile : public Object {
	
public:
	Projectile();
	Projectile(float x, float y);
	
	void draw();

	~Projectile();
};

#endif