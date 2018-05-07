#include "App.h"

static App* singleton;

void explode(int value){		//added the explode function 
    if(!singleton->ball->done()){	//check if the animation has already been done
	singleton->ball->advance();  //start advancing through explosion map
	singleton->redraw();
	glutTimerFunc(32, explode, value); //recursive timer function to keep advancing and redrawing the map 
    }
    if(!singleton->platform->done()){	//check if the animation has already been done
	singleton->platform->advance();  //start advancing through explosion map
	singleton->redraw();
	glutTimerFunc(32, explode, value); //recursive timer function to keep advancing and redrawing the map 
    }
}

void moveP(int value){
    if (singleton->shooting){
	if(singleton->bullet->getY() < .99){
	    singleton->bullet->moveUpP(.09);
	    singleton->redraw();
      	    float bx = singleton->bullet->x;
            float by = singleton->bullet->y;
	    if (singleton->ball->contains(bx, by)){
	        singleton->ball->animate();
	        explode(0);
            
        }
	    glutTimerFunc(32, moveP, value);
	}
    }


}



void app_timer(int value){
    if (singleton->game_over){
        singleton->gameOver->advance();
    }
    
    if (singleton->moving){
        singleton->ball->jump();
        float bx = singleton->ball->x + singleton->ball->w/2;
        float by = singleton->ball->y - singleton->ball->h + 0.1;
        if (singleton->platform->contains(bx, by)){
	    singleton->platform->animate();
	    singleton->ball->animate();
	    explode(0);
            /*singleton->ball->rising = true;
            singleton->ball->yinc +=0.005;
            singleton->ball->xinc = singleton->ball->yinc;
            if (singleton->ball->yinc > 0.15){
                singleton->ball->yinc = 0.15;
            }*/
        }
        
        if (singleton->ball->y - singleton->ball->h < -0.99){
            singleton->moving = false;
            singleton->game_over = true;
            singleton->gameOver->animate();
            
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

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    background = new TexRect("images/back.png", -1, 1, 2, 2);
    ball = new TexRect("images/asteroid.png", "images/exp2_0.png", 4, 4, 0, 0.67, 0.2, 0.2);

    platform = new TexRect("images/spaceship.pod_.1.red_.png", "images/exp2_0.png", 4, 4, 0, -0.7, 0.2, 0.2);
    
    gameOver = new AnimatedRect("images/game_over.png", 7, 1, -1.0, 0.8, 2, 1.2);
    shooting = up = down = left = right = false;
   
    float yy = this->platform->getY();
    float xx = this->platform->getX();
    float ww = this->platform->getW();
    float hh = this->platform->getH();
    
    bullet = new TexRect("images/basicBullet.bmp", xx - ww/2, yy + hh, 0.025, 0.025);
    
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
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    background->draw();
    platform->draw();
    if(shooting){
        bullet->draw();
    }
    ball->draw();
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
   
     if(ball->contains(mx, my)){		//added if statement to check if the image has been clicked
	if(!ball->done()){
	    ball->animate();	//changes animating boolean to true
	    explode(0);	                //starts the advance and redraw recursive function to cycle through map
	}
    }

}

void App::idle(){

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        delete ball;
        delete platform;
        delete gameOver;
        delete background;
        delete this;
        
        exit(0);
    }
    
    if (key == 13){
        ball->x = 0;
        ball->y = 0.67;
        ball->yinc = 0.01;
        ball->xinc = 0.01;
        ball->rising = false;
        game_over = false;
        gameOver->stop();
        moving = true;
    }
   
     if( key == ' '){
	singleton->bullet->setX(singleton->platform->getX() + singleton->platform->getW()/2);
	singleton->bullet->setY(singleton->platform->getY());
	shooting = true;
    }
    moveP(1);
}
