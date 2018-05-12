#ifndef	Game_h
#define Game_h

#include "App.h"
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
	//std::vector<Object*> objList;
	Player *player;
	std::vector<Asteroids*> asteroids;
	std::vector<PowerUp*> Powerups;
	std::vector<Projectile*> bullets;

	TexRect* background;
	AnimatedRect* gameOver;
	Score* score;

	bool moving;
	bool game_over;
	time_t spawnTimer;
public:
	Game();
	
	void tick();
	void draw();
	void specialKeyPress(int key);
	void specialKeyUp(int key);
	void keyPress(unsigned char key);

	~Game();	
	 //time_t spawnTimer;
};
#endif
