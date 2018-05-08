#include "App.h"
#include <vector>

static App* singleton;

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
                /*singleton->ball->rising = true;
                singleton->ball->yinc +=0.005;
                singleton->ball->xinc = singleton->ball->yinc;
                if (singleton->ball->yinc > 0.15){
                    singleton->ball->yinc = 0.15;
                }*/
            }
        
            if ( singleton->score->getScore() > 50 ){
            	singleton->moving = false;
            	singleton->game_over = true;
            	singleton->gameOver->animate();
            
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

/*void App::makeBall() {
	delete ball;
	ball = new TexRect("images/asteroid.png", "images/exp2_0.png", 4, 4, 0, 0.67, 0.2, 0.2);
}*/

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    background = new TexRect("images/back.png", -1, 1, 2, 2);


    //ball = new TexRect("images/asteroid.png", "images/exp2_0.png", 4, 4, 0, 0.67, 0.2, 0.2);

    platform = new TexRect("images/spaceship.pod_.1.red_.png", "images/exp2_0.png", 4, 4, 0, -0.7, 0.2, 0.2);
    
    gameOver = new AnimatedRect("images/game_over.png", 7, 1, -1.0, 0.8, 2, 1.2);
    shooting = up = down = left = right = false;
   
    float yy = this->platform->getY();
    float xx = this->platform->getX();
    float ww = this->platform->getW();
    float hh = this->platform->getH();
	
	score = new Score( 0, 0 );
    
    TexRect *a;
    for (int i = 0; i < 5; i++){			
	float y = ((float)(rand() % 200) / 100)-1;			
	a = new TexRect("images/asteroid.png", "images/exp2_0.png", 4, 4, x, .8, 0.2, 0.2);
	asteroids.push_back(a);
    }

    moving = true;
    game_over = false;
    
    app_timer(1);

}

void App::specialKeyPress(int key){
    if (!game_over){
        if (key == 100){
            left = true;
        }
        if (key == 101){
            up = true;
        }
        if (key == 102){
            right = true;
        }
        if (key == 103){
            down = true;
        }
    }
}

void App::specialKeyUp(int key){
    if (key == 100) {
        left = false;
    }
    if (key == 101) {
        up = false;
    }
    if (key == 102) {
        right = false;
    }
    if (key == 103) {
        down = false;
    }
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 1.0, 1.0);
    
    score->draw(); 
	
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    background->draw();
    platform->draw();
    if(shooting){
	for(unsigned i = 0; i < bullets.size(); i++){
		bullets.at(i)->draw();
	}
        
    }
    for(unsigned i = 0; i < singleton->asteroids.size(); i++){
		asteroids.at(i)->draw();
	}
    //ball->draw();
    gameOver->draw();
   
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
   
     /*if(ball->contains(mx, my)){		//added if statement to check if the image has been clicked
	if(!ball->done()){
	    ball->animate();	//changes animating boolean to true
	    explodeAsteroid(0);	                //starts the advance and redraw recursive function to cycle through map
	    score->add(10);
	}
    }*/

}

void App::idle(){
     if (shooting){
      for (unsigned i = 0; i < bullets.size(); i++){
	
	if(singleton->bullets.at(i)->getY() < .99){
	    singleton->bullets.at(i)->moveUpP(.09);
	    singleton->redraw();
      	    float bx = singleton->bullets.at(i)->x;
            float by = singleton->bullets.at(i)->y;
	    for(unsigned i = 0; i < singleton->asteroids.size(); i++){
		if (singleton->asteroids.at(i)->contains(bx, by)){
  	            singleton->asteroids.at(i)->animate();
	            explodeAsteroid(0);
            	    score->add(10);
                }

            }
	}
	else{
	    bullets.pop_back();
	}
      }	
    }
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        //delete ball;
        delete platform;
        delete gameOver;
        delete background;
		delete score;
        delete this;
        
        exit(0);
    }
    
    if (key == 13){
       /* ball->x = 0;
        ball->y = 0.67;
        ball->yinc = 0.01;
        ball->xinc = 0.01;
        ball->rising = false;
        game_over = false;
        gameOver->stop();
        moving = true;*/
    }
   
     if( key == ' '){
        if (!game_over) {
		TexRect *p = new TexRect("images/basicBullet.bmp", singleton->platform->getX() + singleton->platform->getW()/2, singleton->platform->getY(), 0.025, 0.025);
	
		singleton->bullets.push_back(p);
		shooting = true;
        }
    }
   // projectiles(1);
    // moveP(1);
}
