#ifndef Asteroids_h
#define Asteroids_h
//#include "TexRect.h"

#include "Object.h"

class Asteroids : public Object {

	//TexRect* texture;
public:
	Asteroids();

	void explode();

	void draw();
	
	~Asteroids();
	
};

#endif
