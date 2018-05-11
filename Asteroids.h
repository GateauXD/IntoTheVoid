#ifndef Asteroids_h
#define Asteroids_h
#include "TexRect.h"
class Asteroids
{
	TexRect* texture;
public:
	Asteroids();

	void explode();
	
	~Asteroids();
	
};



#endif
