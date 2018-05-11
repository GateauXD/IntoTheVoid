#ifndef	GAME_H
#define GAME_H value

//#include "Powerup.h"
//#include "Player.h"
//#include "Asteroids.h"
//#include "Bullets.h"
#include "AnimatedRect.h"
#include "TexRect.h"
#include "GlutApp.h"
#include "Score.h"

#include <vector>
#include <stdlib.h>
#include <time.h>

class Game{
	std::vector<Asteroids*> asteroids;
	std::vector<PowerUp*> Powerups;
	std::vector<Projectiles*> bullets;

	TexRect* background;
	Player* player;
	AnimatedRect* gameOver;
	Score* score;

	bool up;
	bool down;
	bool left;
	bool right;
	bool shooting;
	bool moing;
	bool game_over;
	time_t spawnTimer;
public:
	Game();
	
	void draw();
	void specialKeyPress(int key);
	void specialKeyUp(int key);
	void makePlayer();	
	void makeAsteroids(int nums);
	void makePowerup();
	void restart();
	void pause();

	~Game();	
	 time_t spawnTimer;
};
#endif
