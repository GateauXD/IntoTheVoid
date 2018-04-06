#ifndef ENEMY_H
#define ENEMY_H

#include "Ship.h"

#include <stdlib.h>	//rand()
#include <time.h>	//time()

class Enemy : public Ship {
		
public:
	Enemy() {
		float x = (float)(rand() % 80) / 100;			// float between 0 and 0.8
		float y = (float)(rand() % 180 - 80) / 100;		// float between -0.8 and 1
		
		hitbox = new Rect(x, y, 0.2, 0.2); // spawn random enemy on right side of screen
		
		firerate = 5;
		health = 20;
		speed = 0.1;
	}
	Enemy(int rate, int h) {
		float x = (float)(rand() % 80) / 100;			// float between 0 and 0.8
		float y = (float)(rand() % 180 - 80) / 100;		// float between -0.8 and 1
		
		hitbox = new Rect(x, y, 0.2, 0.2); // spawn random enemy on right side of screen
		
		firerate = rate;
		health = h;
		speed = 0.1;
	}
	~Enemy() {}
	
	void movePos(unsigned char key) {
		int move = rand() % 4;							// int between 0 and 3
		switch (move) {
			float x;
			float y;

			case 0:	//up
				y = hitbox->getY();
				if (y + speed <= 1) {
					hitbox->setY(y + speed);
				}
				break;
			case 1:	//left
				x = hitbox->getX();
				if (x - speed >= -1) {
					hitbox->setX(x - speed);
				}
				break;
			case 2:	//down
				y = hitbox->getY();
				if (y - hitbox->getHeight() - speed >= -1) {
					hitbox->setY(y - speed);
				}
				break;
			case 3:	//right
				x = hitbox->getX();
				if (x + hitbox->getWidth() + speed <= 1) {
					hitbox->setX(x + speed);
				}
				break;
		}
	}
};

#endif