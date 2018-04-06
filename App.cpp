#include "App.h"

#include <iostream>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

//	DIFF MODE NEEDS WORK
//
//	int diff = 0;
//	std::cout << "Enter difficulty [1, 10]" << std::endl;
//	std::cin >> diff;
//	if (diff) {
//		game = new Game(diff);
//	}
//	else {
		game = new Game();
//	}
}

void App::draw() {
	if (!game->isWon()) {
		game->draw();
		game->print();
	}
	else {
		exit(0);
	}
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

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
	game->onPress(key);
	
	// Redraw the scene
	redraw();
}
