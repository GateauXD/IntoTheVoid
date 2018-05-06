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
	int score;
public:
	Game() {
		gameOver = false;

		Player *player = new Player();
		objList.push_back(player);
		
		srand (time(NULL));
		Enemy* e = new Enemy();
		objList.push_back(e);
		background =new TexRect("assets/background1.png",-1,1,2,2);
		//test=new Powerup();
	}
	Game(int n) {
		gameOver = false;

		Player *player = new Player();
		objList.push_back(player);
		
		srand (time(NULL));
		Enemy *e;
		for (int i = 0; i < n; i++) {
			e = new Enemy();
			objList.push_back(e);
		}
		background = new TexRect("assets/background1.png",-1,1,2,2);
	}
	~Game() {
		for (unsigned i = 0; i < objList.size(); i++)
			delete objList.at(i);
		delete background;
		//delete test;
	}
	
	bool isOver() const { return gameOver; }
	
	void onClick(float mx, float my) {}

	void onPress(unsigned char key) {}

	
	// Currently draws hitboxes and no background, eventually will draw Textures
	void draw() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glClearColor(0.0, 0.0, 0.0, 1.0);
		
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
		int i = 0;
		while(i < objList.size()){
			if(objList[0]->checkCollision(objList[i]->objectTex->getX(), objList[i]->objectTex->getY())){
				std::cout << "HIT!!!" << std::endl;
			}
			i++;
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
