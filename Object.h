#ifndef OBJECT_H
#define OBJECT_H

#include "Rect.h"

class Object {

protected:
//  Texture sprite;
    Rect *hitbox; // position and collision

public:
	Object();
	~Object();
	
	virtual void checkCollision(int x, int y);
	virtual void getPosition(int &x, int &y); // could return a Vec
};

#endif