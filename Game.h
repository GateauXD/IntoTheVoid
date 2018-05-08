#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <stdlib.h>	//rand()
#include <time.h>	//time()

#include "Player.h"
#include "Enemy.h"
#include "TexRect.h" // for textures
//#include "Projectile.h"
#include "Powerup.h"
#include "Score.h"
#include "App.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Game{
	TexRect* background;
	//Powerup* test;
	bool gameOver;
	bool up;
	bool down;
	bool left;
	bool right;
	bool moving;

	std::vector < Object* > objList;
	Score* score;
public:
	Game() {
		gameOver = false;

		Player *player = new Player();
		objList.push_back(player);
		
		srand (time(NULL));
		spawnEnemies();
		
		background =new TexRect("assets/background1.png",-1,1,2,2);
		//test=new Powerup();
		score = new Score( 0.7, 0.9 );
		
		app_timer(1);
	}

	~Game() {
		for (unsigned i = 0; i < objList.size(); i++){
			delete objList.at(i);
		}
		delete background;
		delete score;
	}
	
	bool isOver() const { return gameOver; }
	
	void onClick(float mx, float my) {}

	void onPress(int key) {
		if (!gameOver){
			if (key == 100){
				left = true;
			}
			if (key == 101){
				up = true;
			}
			if (key == 102){
				right = true;
			}
			if (key == 103){
				down = true;
			}
		}
	}
	
	void onLift(int key) {
		if (key == 100) {
			left = false;
		}
		if (key == 101) {
			up = false;
		}
		if (key == 102) {
			right = false;
		}
		if (key == 103) {
			down = false;
		}
	}

/*
	void specialKeyUp(unsigned char key){
		std::cout << "Called";
		if(key == 'w' || key == 'W')
			up = false;
		if(key == 's' || key == 's')
			down = false;
		if(key == 'a' || key == 'A')
			left = false;
		if(key == 'd' || key == 'D')
			right = false;
	}
*/

	
	// Currently draws hitboxes and no background, eventually will draw Textures
	void draw() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glClearColor(0.0, 0.0, 0.0, 1.0);
		
		// drawing score to corner;
		score->draw();
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		for (unsigned i = 0; i < objList.size(); i++) {
			objList.at(i)->objectTex->draw();
		}

		//test->draw();
		background->draw();


		glFlush();
		glutSwapBuffers();
		
		detectCollision();
	}

	// This sould work now	
	void detectCollision(){
		int i = 1;
		while(i < objList.size()){
			if(objList[0]->checkCollision(objList[i]->objectTex->getX(), objList[i]->objectTex->getY())){
				gameOver = true;
				score->add(5);
			}
			i++;
		}
	}

	void spawnEnemies(){
		Enemy *e;
		float x = .8;
		for (int i = 0; i < 10; i++) {
			float y = 1 - (.2 * i);
			e = new Enemy(x, y);
			objList.push_back(e);
		}
	}

	void app_timer(int value);

//	DEBUG
	void print() 
	{
		//for (unsigned i = 0; i < objList.size(); i++) {
			//float x, y, w, h;
			//objList.at(i)->getHB(x, y, w, h);
			//std::cout << "x=" << x << ", y=" << y << ", w=" << w << ", h=" << h << std::endl;
		//}
	}
};

#endif
