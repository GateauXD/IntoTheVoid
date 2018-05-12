#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player : public Ship {
	bool up;
	bool down;
	bool left;
	bool right;

public:
	Player();
	Player(int rate);
	
	void explode();

	void draw();
	
	~Player();
	
	void movePos(unsigned char key);
	bool isUp();
	bool isDown();
	bool isLeft();
	bool isRight();
	
	void moveUp(float d);
	void moveDown(float d);
	void moveLeft(float d);
	void moveRight(float d);
};

#endif