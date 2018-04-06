#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <stdlib.h>	//rand()
#include <time.h>	//time()

#include "Player.h"
#include "Enemy.h"
//#include "Projectile.h"
//#include "Powerup.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Game {
//  Texture background
	bool gameOver;
	std::vector < Object* > objList;

public:
	Game() {
		gameOver = false;

		Player *player = new Player();
		objList.push_back(player);
		
		srand (time(NULL));
		Enemy* e = new Enemy();
		objList.push_back(e);
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
	}
	~Game() {
		for (unsigned i = 0; i < objList.size(); i++)
			delete objList.at(i);
	}
	
	bool isOver() const { return gameOver; }
	
	void onClick(float mx, float my) {}
	void onPress(unsigned char key) {
		for (unsigned i = 0; i < objList.size(); i++) {
			objList.at(i)->movePos(key);
		}
	}
	// Currently draws hitboxes and no background, eventually will draw Textures
	void draw() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glClearColor(0.0, 0.0, 0.0, 1.0);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		for (unsigned i = 0; i < objList.size(); i++) {
			float x, y, w, h;
			objList.at(i)->getHB(x, y, w, h);
			float r, g, b;
			objList.at(i)->getHBColor(r, g, b);
			
			glColor3d( r, g, b );
			glPolygonMode(GL_FRONT, GL_FILL);
			glBegin(GL_POLYGON);

			glVertex2f( x, y );
			glVertex2f( x + w, y );
			glVertex2f( x + w, y - h );
			glVertex2f( x, y - h );

			glEnd();
		}

		glFlush();
		glutSwapBuffers();
		
//		detectCollision();
	}

	// TODO: Figure out collision
	// THIS FUNCTION DOES NOT WORK AS INTENDED	
//	void detectCollision() {
//		for (unsigned i = 1; i < objList.size(); i++) {	// skips player (obj[0]
//			if (objList.at(i)->checkCollision(objList.at(0)))
//				gameOver = true;
//		}
//	}
	
//	DEBUG
	void print() {
		for (unsigned i = 0; i < objList.size(); i++) {
			float x, y, w, h;
			objList.at(i)->getHB(x, y, w, h);
			std::cout << "x=" << x << ", y=" << y << ", w=" << w << ", h=" << h << std::endl;
		}
	}
};

#endif