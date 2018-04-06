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
	bool win;
	Player *player;
	std::vector < Object* > objList;

public:
	Game() {
		win = false;

		player = new Player();
		objList.push_back(player);
		
		srand (time(NULL));
		Enemy* e = new Enemy();
		objList.push_back(e);
	}
	Game(int n) {
		win = false;

		player = new Player();
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
	
	bool isWon() const {
		return win;
	}
	
	void onClick(float mx, float my) {}
	void onPress(unsigned char key) {
		player->movePos(key);
	}
	void draw() {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// Set background color to black
		glClearColor(0.0, 0.0, 0.0, 1.0);
		
		// Set up the transformations stack
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
		
		// We have been drawing everything to the back buffer
		// Swap the buffers to see the result of what we drew
		glFlush();
		glutSwapBuffers();
	}
	
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