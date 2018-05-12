#include "Player.h"

Player::Player(){
	objectTex = new TexRect("images/spaceship.pod_.1.red_.png","images/exp2_0.png",6,6,0, -0.7, .2, .2);
	firerate = 5;
	speed = 0.05;
	
	up = down = left = right  = false;
}
Player::Player(int rate){
	objectTex = new TexRect("images/spaceship.pod_.1.red_.png","images/exp2_0.png",6,6,0, -0.7, .2, .2);
	firerate = rate;
	speed = 0.05;
	
	up = down = left = right = false;
}
Player::~Player() {
	//std::cout << "Deleting Player" << std::endl;
}

//Change these to fuctions. The move up and down things
void Player::movePos(unsigned char key) {
	switch (key) {
		float x;
		float y;

		case 101:	//up
			y = objectTex->getY();
			if (y + speed <= 1.02) {
				objectTex->setY(y + speed);
			}
			break;
		case 100:	//left
			x = objectTex->getX();
			if (x - speed >= -1.02) {
				objectTex->setX(x - speed);
			}
			break;
		case 103:	//down
			y = objectTex->getY();
			if (y - objectTex->getH() - speed >= -1.02) {
				objectTex->setY(y - speed);
			}
			break;
		case 102:	//right
			x = objectTex->getX();
			if (x + objectTex->getW() + speed <= 1.02) {
				objectTex->setX(x + speed);
			}
			break;
		
	}
}

bool Player::isUp() {
	return up;
}
bool Player::isDown() {
	return down;
}
bool Player::isLeft() {
	return left;
}
bool Player::isRight() {
	return right;
}

void Player::moveUp(float d){
	objectTex->moveUp(d);
}
void Player::moveDown(float d){
	objectTex->moveDown(d);
}
void Player::moveLeft(float d){
	objectTex->moveLeft(d);
}
void Player::moveRight(float d){
	objectTex->moveRight(d);
}

void Player::draw(){
	objectTex->draw();
}

void Player::explode(){
	
}
