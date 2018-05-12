#include "Game.h"
#include "App.h"
static App* p;
//static Game* singleton;

void explodeAsteroid(int value){		//added the explode function 
	for (unsigned i = 0; i < p->game->asteroids.size();i++){
		if(!p->game->asteroids.at(i)->getHB()->done()){	//check if the animation has already been done
			p->game->asteroids.at(i)->getHB()->advance();  //start advancing through explosion map
			//p->game->redraw();
			glutTimerFunc(32, explodeAsteroid, value); //recursive timer function to keep advancing and redrawing the map 
		}
	}
}

void explodeShip(int value){
    if(!p->game->player->getHB()->done()){	//check if the animation has already been done
		p->game->player->getHB()->advance();  //start advancing through explosion map
		//p->game->redraw();
		glutTimerFunc(32, explodeShip, value); //recursive timer function to keep advancing and redrawing the map 
	}
}

void app_timer(int value){
	if (p->game->game_over){
		p->game->gameOver->advance();
	}

	if (p->game->moving){

		for(unsigned i = 0; i < p->game->asteroids.size(); i++){
			p->game->asteroids.at(i)->getHB()->jump();
			float bx = p->game->asteroids.at(i)->getHB()->x + p->game->asteroids.at(i)->getHB()->w/2;
			float by = p->game->asteroids.at(i)->getHB()->y - p->game->asteroids.at(i)->getHB()->h + 0.1;
			if (p->game->player->getHB()->contains(bx, by)){
				p->game->player->getHB()->animate();
				p->game->asteroids.at(i)->getHB()->animate();
				explodeShip(0);
				p->game->moving = false;
				p->game->game_over = true;
				p->game->gameOver->animate();
			}
		}

		for(unsigned i = 0; i < p->game->Powerup.size(); i++){
			//singleton->Powerup.at(i)->jump();
			float bx = p->game->Powerup.at(i)->getHB()->x + p->game->Powerup.at(i)->getHB()->w/2;
			float by = p->game->Powerup.at(i)->getHB()->y - p->game->Powerup.at(i)->getHB()->h + 0.1;
			if (p->game->player->getHB()->contains(bx, by)){
				p->game->score->add(50);
				delete p->game->Powerup.at(i);
				p->game->Powerup.erase(p->game->Powerup.begin() + i);
			}
		}
	}

	if (p->game->player->isUp()){
		p->game->player->moveUp(0.05);
	}
	if (p->game->player->isDown()){
		p->game->player->moveDown(0.05);
	}
	if (p->game->player->isLeft()){
		p->game->player->moveLeft(0.05);
	}
	if (p->game->player->isRight()){
		p->game->player->moveRight(0.05);
	}

	if (p->game->game_over){
		//p->game->redraw();
		glutTimerFunc(100, app_timer, value);
	}
	else{
		if (p->game->player->isUp() || p->game->player->isDown() || p->game->player->isLeft() || p->game->player->isRight() || p->game->moving && !p->game->game_over){
			//p->game->redraw();
			glutTimerFunc(16, app_timer, value);
		}
	}
}

Game::Game(App* a){
	game_over = false;
	p=a;

	background = new TexRect("assests/background1.png", -1, 1, 2, 2);
	gameOver = new AnimatedRect("images/game_over.png", 7, 1, -1.0, 0.8, 2, 1.2);
	score = new Score(0.7,0.9);

	game_over = false;
	moving = true;
	
	player = new Player();
	//objList.push_back(player);
		
	srand (time(NULL));
	//spawnEnemies(5);
	
	makeAsteroids(5);
	makePowerup(1);
	
	time(&spawnTimer);
	app_timer(1);
}
/*
void spawnEnemies(int n) {
	PowerUp *e;
	float x = ((float)(rand() % 200) / 100)-1;
	float y = ((float)(rand() % 200) / 100)-1;
	for (int i = 0; i < 10; i++) {
		e = new Enemy(x, y);
		objList.push_back(e);
	}
}*/

void Game::makeAsteroids(int n) {
	Asteroids *a;
	for (int i = 0; i < n; i++){			
		float x = ((float)(rand() % 200) / 100)-1;			
		a = new Asteroids(x, .8);
		asteroids.push_back(a);
	}
}

void Game::makePowerup(int n) {
	PowerUp *a;
	for (int i = 0; i < n; i++){			
		float x = ((float)(rand() % 160) / 100) - 0.8;
		float y = ((float)(rand() % 160) / 100) - 0.8;		
		a = new PowerUp(x, y);
		Powerup.push_back(a);
	}
}

void Game::makeBullet() {			
	float x = player->getX() + player->getW()/2;
	float y = player->getY();		
	Projectile *a = new Projectile(x, y);
	bullets.push_back(a);
}

void Game::draw(){
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.0,0.0,1.0,1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	background->draw();
	score->draw();

	player->draw();

	for(unsigned i = 0; i < bullets.size(); i++){
		bullets.at(i)->draw();
	}

	for(unsigned i = 0; i < asteroids.size(); i++){
		asteroids.at(i)->draw();
	}

	for(unsigned i = 0; i < Powerup.size(); i++){
		Powerup.at(i)->draw();
	}

	gameOver->draw();

	glFlush();
	glutSwapBuffers();
}

void Game::specialKeyPress(int key){
	if(!game_over){
	player->movePos(key);
	}
}

void Game::specialKeyUp(int key){
	//if(!game_over){
		//switch(key){
			//case 100:
			//left = false;
			//case 101:
			//player->isUp() = false;
			//case 102:
			//right = false;
			//case 103:
			//down = false;
		//}
	//}
}

void Game::tick(){
	for (unsigned i = 0; i < bullets.size(); i++){
		if(bullets.at(i)->getY() < .99){
			bullets.at(i)->getHB()->moveUpP(.09);
			//redraw();
			float bx = bullets.at(i)->getHB()->x;
			float by = bullets.at(i)->getHB()->y;
			for(unsigned i = 0; i < asteroids.size(); i++){
				if (asteroids.at(i)->getHB()->contains(bx, by)){
					asteroids.at(i)->getHB()->animate();
					explodeAsteroid(0);
					score->add(10);
					delete asteroids.at(i);
					asteroids.erase(asteroids.begin() + i);
				}

			}
		}
		else{
			delete bullets.at(i);
			bullets.erase(bullets.begin() + i);
		}
	}
	time_t newTime;
	time(&newTime);
	if (difftime(newTime, spawnTimer) > 3 || asteroids.size() < 3) {
		makeAsteroids(1);
		spawnTimer = newTime;
	}
	if (Powerup.size() < 3) {
		makePowerup(1);
	}
}

void Game::keyPress(unsigned char key) {
	if (key == 27){
        // Exit the app when Esc key is pressed
		delete player;
		
		for(unsigned i = 0; i < bullets.size(); i++){
			delete bullets.at(i);
		}


		for(unsigned i = 0; i < asteroids.size(); i++){
			delete asteroids.at(i);
		}


		for(unsigned i = 0; i < Powerup.size(); i++){
			delete Powerup.at(i);
		}

		
		delete this;

		exit(0);
	}

	if( key == ' '){
		if (!game_over) {
			makeBullet();
			//shooting = true;
		}
	}


}
