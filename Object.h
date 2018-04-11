#ifndef OBJECT_H
#define OBJECT_H

#include "Rect.h"

class Object {
	
protected:
//  Texture sprite;
    Rect *hitbox; // position and collision
	float speed;

public:


	
	float getSpeed() const { return speed; }
	
	//	virtual keyword added to allow for different child collision types (eg. circular)
	virtual bool checkCollision(float x, float y) {
		return hitbox->contains(x,y);
	}
	virtual void getPosition(float &x, float &y) { // could return a Vec
		x = hitbox->getX() + hitbox->getWidth() / 2;
		y = hitbox->getY() + hitbox->getHeight() / 2;
	}
	virtual void movePos(unsigned char key) = 0; // may not need pure virtual (powerup), just want to style on 'em
	
//hitbox
	virtual void getHB(float &x, float &y, float &w, float &h) {
		x = hitbox->getX();
		y = hitbox->getY();
		w = hitbox->getWidth();
		h = hitbox->getHeight();
	}
	virtual void getHBColor(float &r, float &g, float &b) {
		r = hitbox->getRed();
		g = hitbox->getGreen();
		b = hitbox->getBlue();
	}

		virtual ~Object() {
		delete hitbox;
	}
};


#endif