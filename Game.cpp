#include "Game.h"
static App* p;
Game::Game(){
	game_over = false;
	p=App::app;
	//player = new Player();
	background = new TexRect("assests/background1.png", -1, 1, 2, 2);
	//TODO: Change the location of this score's arguments
	//score = new Score(0.7,0.9);

	up = down = left = right = shooting = game_over = false;

	moving = true;

	makeAsteroids(5);
	makePowerup(1);
}
void explodeShip(int value){
    if(!p->platform->done()){	//check if the animation has already been done
	p->platform->advance();  //start advancing through explosion map
	p->redraw();
	glutTimerFunc(32, explodeShip, value); //recursive timer function to keep advancing and redrawing the map 
}
}
void Game::draw(){
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.0,0.0,1.0,1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	background->draw();
	//player->draw();
	//score->draw();
	// if(shooting){
	// 	for(unsigned i = 0; i < bullets.size(); i++){
	// 		bullets.at(i)->draw();
	// 	}
	// }

	for(unsigned i = 0; i < asteroids.size(); i++){
		asteroids.at(i)->draw();
	}

	for(unsigned i = 0; i < Powerups.size(); i++){
		Powerups.at(i)->draw();
	}

	//gameOver->draw();

	glFlush();
	glutSwapBuffers();

}

void Game::specialKeyPress(int key){
	if(!game_over){
		switch(key){
			case 100:
			left = true;
			case 101:
			up = true;
			case 102:
			right = true;
			case 103:
			down = true;
		}
	}
}

void Game::specialKeyUp(int key){
	if(!game_over){
		switch(key){
			case 100:
			left = false;
			case 101:
			up = false;
			case 102:
			right = false;
			case 103:
			down = false;
		}
	}
}

void Game::makePowerup(int num){
	for(int i = 0; i < num; i++){
		PowerUp* a = new PowerUp();
		Powerups.push_back(a);
		//Redraw();
	}
}

void Game::makeAsteroids(int num){
	for(int i = 0; i < num; i++){
		Asteroids* a = new Asteroids();
		asteroids.push_back(a);
		//Redraw();
	}
}

void Game::makePlayer(){
	//player = new Player();
}

void Game::restart(){
	
}

void Game::pause(){

}
