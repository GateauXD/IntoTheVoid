#ifndef ENEMY_H
#define ENEMY_H

#include "Ship.h"

#include <stdlib.h>	//rand()
#include <time.h>	//time()

class Enemy : public Ship {
		
public:
	Enemy() {
		srand (time(NULL));
		float x = (float)(rand() % 80) / 100;			// float between 0 and 0.8
		float y = (float)(rand() % 180 - 80) / 100;		// float between -0.8 and 1
		
		hitbox = new Rect(x, y, .2, .2); // spawn random enemy on right side of screen
		
		firerate = 5;
		health = 20;
	}
	Enemy(int rate, int h) {
		srand (time(NULL));
		float x = (float)(rand() % 80) / 100;			// float between 0 and 0.8
		float y = (float)(rand() % 180 - 80) / 100;		// float between -0.8 and 1
		
		hitbox = new Rect(x, y, .2, .2); // spawn random enemy on right side of screen
		
		firerate = rate;
		health = h;
	}
	~Enemy();
};

/* // LINKER ERROR, MAKING INLINE
Enemy::Enemy() {
	srand (time(NULL));
	float x = (float)(rand() % 80) / 100;			// float between 0 and 0.8
	float y = (float)(rand() % 180 - 80) / 100;		// float between -0.8 and 1
	
	hitbox = new Rect(x, y, .2, .2); // spawn random enemy on right side of screen
	
	firerate = 5;
	health = 20;
}

Enemy::Enemy(int rate, int h) {
	srand (time(NULL));
	float x = (float)(rand() % 80) / 100;			// float between 0 and 0.8
	float y = (float)(rand() % 180 - 80) / 100;		// float between -0.8 and 1
	
	hitbox = new Rect(x, y, .2, .2); // spawn random enemy on right side of screen
	
	firerate = rate;
	health = h;
}
*/

#endif