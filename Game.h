#ifndef GAME_H
#define GAME_H

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