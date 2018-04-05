#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Player.h"
#include "Enemy.h"
//#include "Projectile.h"
//#include "Powerup.h"

class Game {
	bool win;
	Player *player;
	std::vector < Enemy* > enemyList;

public:
	Game() {
		win = false;
		
		player = new Player();
		
		Enemy* e = new Enemy();
		enemyList.push_back(e);
	}
	Game(int n) {
		win = false;
		
		player = new Player();
		
		Enemy *e;
		for (int i = 0; i < n; i++) {
			e = new Enemy();
			enemyList.push_back(e);
		}
	}
	~Game() {
		delete player;
		for (int i = 0; i < enemyList.size(); i++)
			delete enemyList.at(i);
	}
	
	bool isWon() const {
		return win;
	}
	
	void onClick(float mx, float my) {}
	void onPress(unsigned char key) {
		player->movePos(key);
	}
};

#endif