#ifndef Asteroids_h
#define Asteroids_h

#include "Ship.h"

class Asteroids : public Ship {

public:
	Asteroids();
	Asteroids(float x, float y);

	void explode();

	void draw();
	
	~Asteroids();
	
};

#endif
