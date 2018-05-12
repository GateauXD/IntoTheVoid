#ifndef	Game_h
#define Game_h

#include "PowerUp.h"
#include "Player.h"
#include "Asteroids.h"
#include "Projectile.h"
#include "AnimatedRect.h"
#include "TexRect.h"
#include "GlutApp.h"
#include "Score.h"

#include <vector>
#include <stdlib.h>	//rand()
#include <time.h>	//time()

class Game {
public:
	Player *player;
	std::vector<Asteroids*> asteroids;
	std::vector<PowerUp*> Powerup;
	std::vector<Projectile*> bullets;

	TexRect* background;
	AnimatedRect* gameOver;
	Score* score;

	bool moving;
	bool game_over;

	Game();
	
	void tick();
	void draw();
	void specialKeyPress(int key);
	void specialKeyUp(int key);
	void keyPress(unsigned char key);
	void makePowerup(int n);
	void makeAsteroids(int n);
	void makeBullet();
	void makeBall(int n);
	~Game();	
	 time_t spawnTimer;
};
#endif
