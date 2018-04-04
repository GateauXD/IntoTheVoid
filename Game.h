#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Powerup.h"

class Game {
	bool win;
public:
	Game() {
		win = false;
	}
	~Game() {}
	
	bool isWon() const {
		return win;
	}
	
	void onClick(float mx, float my) {}
	void onPress(unsigned char key) {}
};

#endif