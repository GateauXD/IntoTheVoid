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

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Game {
	TexRect* background;
	//Powerup* test;
	bool gameOver;
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
	}

	~Game() {
		for (unsigned i = 0; i < objList.size(); i++)
			delete objList.at(i);
		delete background;
		//delete test;
		delete score;
	}
	
	bool isOver() const { return gameOver; }
	
	void onClick(float mx, float my) {}

	void onPress(unsigned char key) {}

	
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
				std::cout << "HIT!!!" << std::endl;
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
