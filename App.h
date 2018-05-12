#ifndef App_hpp
#define App_hpp

#include "Score.h"
#include <vector>
#include "Game.h"
class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    
    void specialKeyPress(int key);
    
    void specialKeyUp(int key);
    
    void idle();
	
    static App* app;

	friend class Game;
    Game* game; 
};

#endif
