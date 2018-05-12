#include "Asteroids.h"

Asteroids::Asteroids(){
	objectTex = new TexRect("images/asteroid.png", "images/exp2_0.png", 4,4,0,.8,.2,.2);
}
Asteroids::Asteroids(float x, float y){
	objectTex = new TexRect("images/asteroid.png", "images/exp2_0.png", 4,4,x,y,.2,.2);
}

void Asteroids::draw(){
	objectTex->draw();
}

void Asteroids::explode(){
	
}

Asteroids::~Asteroids() {}
