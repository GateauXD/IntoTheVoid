#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player : public Ship {
		
public:
	Player(){
		hitbox = new Rect(-1, .1f, .2f, .2f); //spawn at left side of screen
		
		firerate = 5;
		health = 20;
		speed = 0.1f;
	}
	Player(int rate, int h){
		hitbox = new Rect(-1, .1f, .2f, .2f); //spawn at left side of screen
		
		firerate = rate;
		health = h;
		speed = 0.1f;
	}
	~Player();
	
	void movePos(unsigned char key) {
		switch (key) {
			float x;
			float y;

			case 'w':	//up
				y = hitbox->getY();
				if (y + speed < 1) {
					hitbox->setY(y + speed);
				}
				break;
			case 'a':	//left
				x = hitbox->getX();
				if (x - speed > -1) {
					hitbox->setX(x - speed);
				}
				break;
			case 's':	//down
				y = hitbox->getY();
				if (y - hitbox->getHeight() - speed > -1) {
					hitbox->setX(y - speed);
				}
				break;
			case 'd':	//right
				x = hitbox->getX();
				if (x + hitbox->getWidth() + speed < 1) {
					hitbox->setX(x + speed);
				}
				break;
		}
	}
};

/* // LINKER ERROR, MAKING INLINE
Player::Player() {
	hitbox = new Rect(-1, .1f, .2f, .2f); //spawn at left side of screen
	
	firerate = 5;
	health = 20;
	speed = 0.1f;
}

Player::Player(int rate, int h) {
	hitbox = new Rect(-1, .1f, .2f, .2f); //spawn at left side of screen
	
	firerate = rate;
	health = h;
	speed = 0.1f;
}

void Player::movePos(unsigned char key) {
	switch (key) {
		float x;
		float y;

		case 'w':	//up
			y = hitbox->getY();
			if (y + speed < 1) {
				hitbox->setY(y + speed);
			}
			break;
		case 'a':	//left
			x = hitbox->getX();
			if (x - speed > -1) {
				hitbox->setX(x - speed);
			}
			break;
		case 's':	//down
			y = hitbox->getY();
			if (y - hitbox->getHeight() - speed > -1) {
				hitbox->setX(y - speed);
			}
			break;
		case 'd':	//right
			x = hitbox->getX();
			if (x + hitbox->getWidth() + speed < 1) {
				hitbox->setX(x + speed);
			}
			break;
	}
}
*/

#endif