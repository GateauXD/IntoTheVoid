#include "App.h"

static App* singleton;

#include <iostream>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

	game = new Game();
}

void App::draw() {
	if (!game->isOver()) {
		game->draw();
	}
	else {
		system("PAUSE");
		exit(0);
	}
}

void App::app_timer(int value){
	if (singleton->game->isOver() ){
		//game_over->advance();
		singleton->game->end();
	}
	if (singleton->up){
		//singleton->objList[0]->objectTex->moveUp(0.05);
		singleton->game->moveUp();
	}
	if (singleton->down){
		//singleton->objList[0]->objectTex->moveDown(0.05);
		singleton->game->moveDown();
	}
	if (singleton->left){
		//singleton->objList[0]->objectTex->moveLeft(0.05);
		singleton->game->moveLeft();
	}
	if (singleton->right){
		//singleton->objList[0]->objectTex->moveRight(0.05);
		singleton->game->moveRight();
	}
	
	if (singleton->gameOver){
		singleton->redraw();
		glutTimerFunc(100, app_timer, value);
	}
	else{
		if (singleton->game->getUp() || singleton->game->getDown() || singleton->game->getLeft() || singleton->game->getRight() || singleton->game->isMoving() && !singleton->game->isOver() ){
			singleton->redraw();
			glutTimerFunc(16, app_timer, value);
		}
	}   
}

void App::specialKeyPress(int key){
    game->onPress(key);
	
	// Redraw the scene
    redraw();
}

void App::specialKeyUp(int key){
    game->onLift(key);
	
	// Redraw the scene
    redraw();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
	
	game->onClick(mx, my);
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::idle(){
	redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
	
	// Redraw the scene
	redraw();
}
