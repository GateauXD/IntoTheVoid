#include "App.h"
static App* singleton;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
	std::cout<<"App\n";
	//singleton = this;
	//app= singleton;
	mx = 0.0;
	my = 0.0;
	
	game = new Game(this);

	std::cout<<"App Done\n";
}

void App::specialKeyPress(int key){
	game->specialKeyPress(key);
	redraw();
}

void App::specialKeyUp(int key){
	game->specialKeyUp(key);
	redraw();
}

void App::draw() {
	game->draw();
}

void App::mouseDown(float x, float y){}

void App::mouseDrag(float x, float y){}


void App::idle(){
	game->tick();
	redraw();
}

void App::keyPress(unsigned char key) {
	game->keyPress(key);
	if (key == 27){
        // Exit the app when Esc key is pressed
		delete this;

		exit(0);
	}
	redraw();
}
