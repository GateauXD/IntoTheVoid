#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "TexRect.h"
#include "AnimatedRect.h"
#include "Score.h"
#include <vector>

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
	
	void makeBall();
    
    std::vector< TexRect*> asteroids;
    
    TexRect* platform;
    
    TexRect* background;
    
    std::vector< TexRect* > bullets;
    
    AnimatedRect* gameOver;
	
	Score* score;
    
    bool up;
    bool down;
    bool left;
    bool right;
    bool shooting;
    bool moving;
    bool game_over;

    
    
};

#endif
