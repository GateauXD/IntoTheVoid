#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Game.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
	Game *game;

public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
	~App() {
		std::cout<<"Deleting Game.\n";
		delete game;
	}
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    void specialKeyUp(int key);
	void specialKeyPress(int key);
	friend void app_timer( int );
	void idle();
};

#endif
