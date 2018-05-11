#include "Asteroids.h"

Asteroids::Asteroids(){
	float x = ((float)(rand() % 200)/100) - 1;
	texture = ("images/asteroid.png", "images/exp2_0.png", 4,4,x,.8,.2,.2);
}

Asteroids::explode(){
	
}