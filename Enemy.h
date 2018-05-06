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
		
		objectTex = new TexRect("assets/PlayerShip.bmp",-1, .1, .2, .2);
		
		firerate = 5;
		health = 20;
		speed = 0.1;
	}
	Enemy(int rate, int h) {
		float x = (float)(rand() % 80) / 100;			// float between 0 and 0.8
		float y = (float)(rand() % 180 - 80) / 100;		// float between -0.8 and 1
		
		objectTex = new TexRect("assets/PlayerShip.bmp",-1, .1, .2, .2);
		
		firerate = rate;
		health = h;
		speed = 0.1;
	}
	virtual ~Enemy() {}
	
	virtual void movePos(unsigned char key) {
		int move = rand() % 4;							// int between 0 and 3
		switch (move) {
			float x;
			float y;

			case 0:	//up
				y = objectTex->getY();
				if (y + speed <= 1) {
					objectTex->setY(y + speed);
				}
				break;
			case 1:	//left
				x = objectTex->getX();
				if (x - speed >= -1) {
					objectTex->setX(x - speed);
				}
				break;
			case 2:	//down
				y = objectTex->getY();
				if (y - objectTex->getHeight() - speed >= -1) {
					objectTex->setY(y - speed);
				}
				break;
			case 3:	//right
				x = objectTex->getX();
				if (x + objectTex->getWidth() + speed <= 1) {
					objectTex->setX(x + speed);
				}
				break;
		}
	}
};

#endif
