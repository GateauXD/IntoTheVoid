#ifndef OBJECT_H
#define OBJECT_H

#include "Rect.h"

class Object {
	
protected:
//  Texture sprite;
    Rect *hitbox; // position and collision
	float speed;

public:

	~Object() {
		delete hitbox;
	}
	
	float getSpeed() const { return speed; }
	
	bool checkCollision(float x, float y) {
		return hitbox->contains(x,y);
	}
	void getPosition(float &x, float &y) { // could return a Vec
		x = hitbox->getX() + hitbox->getWidth() / 2;
		y = hitbox->getY() + hitbox->getHeight() / 2;
	}
};

/* // LINKER ERROR, MAKING INLINE
Object::~Object() {
	delete hitbox;
}

bool Object::checkCollision(float x, float y) {
	return hitbox->contains(x,y);
}

void Object::getPosition(float &x, float &y) {
	x = hitbox->getX() + hitbox->getWidth() / 2;
	y = hitbox->getY() + hitbox->getHeight() / 2;
}
*/

#endif