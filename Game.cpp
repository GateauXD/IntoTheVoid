#include "Game.h"

void Game::end() {
	
}
void Game::moveUp() {
	objList[0]->objectTex->moveUp(0.05);
}
void Game::moveDown(){
	objList[0]->objectTex->moveDown(0.05);
}
void Game::moveLeft(){
	objList[0]->objectTex->moveLeft(0.05);
}
void Game::moveRight(){
	objList[0]->objectTex->moveRight(0.05);
}

bool Game::getUp(){
	return up;
}
bool Game::getDown(){
	return down;
}
bool Game::getLeft(){
	return left;
}
bool Game::getRight(){
	return right;
}

bool Game::isMoving(){
	return moving;
}
bool Game::isOver(){
	return gameOver;
}