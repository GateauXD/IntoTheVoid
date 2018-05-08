#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

#include <iostream>

class Player : public Ship {
		
public:
	Player(){
		objectTex = new TexRect("assets/PlayerShip.bmp","assets/fireball.bmp",6,6,-1, .1, .2, .2);
		firerate = 5;
		health = 20;
		speed = 0.05;
	}
	Player(int rate, int h){
		objectTex = new TexRect("assets/PlayerShip.bmp","assets/fireball.bmp",6,6,-1, .1, .2, .2);
		firerate = rate;
		health = h;
		speed = 0.05;
	}
	~Player() {
		std::cout << "Deleting Player" << std::endl;
	}
	
	//Change these to fuctions. The move up and down things
	void movePos(unsigned char key) {
		switch (key) {
			float x;
			float y;

			case 'w':	//up
				y = objectTex->getY();
				if (y + speed <= 1.02) {
					objectTex->setY(y + speed);
				}
				break;
			case 'a':	//left
				x = objectTex->getX();
				if (x - speed >= -1.02) {
					objectTex->setX(x - speed);
				}
				break;
			case 's':	//down
				y = objectTex->getY();
				if (y - objectTex->getHeight() - speed >= -1.02) {
					objectTex->setY(y - speed);
				}
				break;
			case 'd':	//right
				x = objectTex->getX();
				if (x + objectTex->getWidth() + speed <= 1.02) {
					objectTex->setX(x + speed);
				}
				break;
		}
	}
};

#endif
