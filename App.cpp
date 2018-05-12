#include "App.h"
static App* singleton;

/*
void explodeAsteroid(int value){		//added the explode function 
	for (unsigned i = 0; i < singleton->asteroids.size();i++){
		if(!singleton->asteroids.at(i)->done()){	//check if the animation has already been done
			singleton->asteroids.at(i)->advance();  //start advancing through explosion map
			singleton->redraw();
			glutTimerFunc(32, explodeAsteroid, value); //recursive timer function to keep advancing and redrawing the map 
		}
	}
}

void explodeShip(int value){
    if(!singleton->platform->done()){	//check if the animation has already been done
		singleton->platform->advance();  //start advancing through explosion map
		singleton->redraw();
		glutTimerFunc(32, explodeShip, value); //recursive timer function to keep advancing and redrawing the map 
	}
}

void app_timer(int value){
	if (singleton->game_over){
		singleton->gameOver->advance();
	}

	if (singleton->moving){

		for(unsigned i = 0; i < singleton->asteroids.size(); i++){
			singleton->asteroids.at(i)->jump();
			float bx = singleton->asteroids.at(i)->x + singleton->asteroids.at(i)->w/2;
			float by = singleton->asteroids.at(i)->y - singleton->asteroids.at(i)->h + 0.1;
			if (singleton->platform->contains(bx, by)){
				singleton->platform->animate();
				singleton->asteroids.at(i)->animate();
				explodeShip(0);
				singleton->moving = false;
				singleton->game_over = true;
				singleton->gameOver->animate();
			}
		}

		for(unsigned i = 0; i < singleton->Powerup.size(); i++){
			//singleton->Powerup.at(i)->jump();
			float bx = singleton->Powerup.at(i)->x + singleton->Powerup.at(i)->w/2;
			float by = singleton->Powerup.at(i)->y - singleton->Powerup.at(i)->h + 0.1;
			if (singleton->platform->contains(bx, by)){
				singleton->score->add(50);
				delete singleton->Powerup.at(i);
				singleton->Powerup.erase(singleton->Powerup.begin() + i);
			}
		}
	}

	if (singleton->up){
		singleton->platform->moveUp(0.05);
	}
	if (singleton->down){
		singleton->platform->moveDown(0.05);
	}
	if (singleton->left){
		singleton->platform->moveLeft(0.05);
	}
	if (singleton->right){
		singleton->platform->moveRight(0.05);
	}

	if (singleton->game_over){
		singleton->redraw();
		glutTimerFunc(100, app_timer, value);
	}
	else{
		if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over){
			singleton->redraw();
			glutTimerFunc(16, app_timer, value);
		}
	}
}
*/

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


void App::mouseDown(float x, float y){
    // Update app state
	//mx = x;
	//my = y;
}

void App::mouseDrag(float x, float y){
    // Update app state
	//mx = x;
	//my = y;

   // if(ball->contains(mx, my)){		//added if statement to check if the image has been clicked
		//if(!ball->done()){
			//ball->animate();		//changes animating boolean to true
			//explodeAsteroid(0);	    //starts the advance and redraw recursive function to cycle through map
			//score->add(10);
		//}
  //  }
}


void App::idle(){
	game->tick();
	redraw();
}

void App::keyPress(unsigned char key) {
	game->keyPress(key);
	redraw();
}
