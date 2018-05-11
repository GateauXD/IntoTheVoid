#include "GAME_H"

Game::Game(){
	game_over = false;
	
	player = new Player();
	background = new TextRect("assests/background1.png", -1, 1, 2, 2);
	//TODO: Change the location of this score's arguments
	score = new Score(0.7,0.9);

	up = down = left = right = shooting = game_over = false;

	moving = true;

	makeAsteroids(5);
	makePowerup(1);
}

void Game::draw(){
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.0,0.0,1.0,1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	background->draw();
	player->draw();
	score0->draw();
	if(shooting){
		for(unsigned i = 0; i < bullets.size(); i++){
			bullets.at(i)->draw();
		}
	}

	for(unsigned i = 0; i < asteroids.size(); i++){
		asteroids.at(i)->draw();
	}

	for(unsigned i = 0; i < Powerups.size(); i++){
		Powerups.at(i)->draw();
	}

	//gameOver->draw();

	glFLush();
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

void Game::idle(){

}

void Game::makePlayer(){
	player = new Player();
}

void Game::restart(){

}

void Game::pause(){

}