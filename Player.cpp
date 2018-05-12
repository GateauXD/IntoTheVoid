 #include "Player.h"

Player::Player(){
	objectTex = new TexRect("assets/PlayerShip.bmp","assets/fireball.bmp",6,6,0, -0.7, .2, .2);
	firerate = 5;
	speed = 0.05;
	
	up = down = left = right = shooting = false;
}
Player::Player(int rate){
	objectTex = new TexRect("assets/PlayerShip.bmp","assets/fireball.bmp",6,6,0, -0.7, .2, .2);
	firerate = rate;
	speed = 0.05;
	
	up = down = left = right = shooting = false;
}
~Player::Player() {
	std::cout << "Deleting Player" << std::endl;
}

//Change these to fuctions. The move up and down things
void Player::movePos(unsigned char key) {
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

void Player::setUp(bool t) {
	up = t;
}
void Player::setDown(bool t) {
	down = t;
}
void Player::setLeft(bool t) {
	left = t;
}
void Player::setRight(bool t) {
	right = t;
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
	objectTex->jump();
}

void Player::explode(){
	
}
