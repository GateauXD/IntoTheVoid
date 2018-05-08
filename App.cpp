#include "App.h"

static App* singleton;

#include <iostream>

void app_timer(int value){
	//std::cout<<"App timer.\n ";
	if (singleton->game->isOver()==true){
		
		//game_over->advance();
		singleton->game->end();
	}
	std::cout<<"App timer.\n";
	 if (singleton->game->getUp()){
		//std::cout<<"App timer 2.\n";
		//singleton->objList[0]->objectTex->moveUp(0.05);
		singleton->game->moveUp();
	}
	//std::cout<<"App timer.\n";
	 if (singleton->game->getDown()){
		//std::cout<<"App timer 3.\n";
		//singleton->objList[0]->objectTex->moveDown(0.05);
		singleton->game->moveDown();
	}
	//std::cout<<"App timer.\n";
	 if (singleton->game->getLeft()){
		//std::cout<<"App timer 4.\n";
		//singleton->objList[0]->objectTex->moveLeft(0.05);
		singleton->game->moveLeft();
	}
	//std::cout<<"App timer.\n";
	 if (singleton->game->getRight()){
		//std::cout<<"App timer 5.\n";
		//singleton->objList[0]->objectTex->moveRight(0.05);
		singleton->game->moveRight();
	}
	//std::cout<<"App timer.\n";
	 if (singleton->game->isOver()){
		//std::cout<<"App timer 6.\n";
		singleton->redraw();
		glutTimerFunc(100, app_timer, value);
	}
	//std::cout<<"App timer.\n";
	if ((singleton->game->getUp() || singleton->game->getDown() || singleton->game->getLeft() || singleton->game->getRight() || singleton->game->isMoving()) && (!singleton->game->isOver()) ){
			//std::cout<<"Drawing.\n";
			singleton->draw();
			glutTimerFunc(16, app_timer, value);
		}
	//std::cout<<"App timer.\n";
	 
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
	//std::cout<<"Creating App.\n";
    mx = 0.0;
    my = 0.0;

	game = new Game();
	singleton=this;
	app_timer(1);
	//std::cout<<"Done App.\n";
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


