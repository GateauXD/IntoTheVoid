#ifndef OBJECT_H
#define OBJECT_H

#include "TexRect.h"
//#include "Circle.h"

class Object {
    TexRect* objectTex;
    float speed;

public:
	
	float getSpeed() const;
	TexRect* getHB() const;
	
	virtual bool checkCollision(float x, float y); // virtual keyword added to allow for different child collision types (eg. circular)
	virtual void getPosition(float &x, float &y);
	virtual void movePos(unsigned char key)=0; // may not need pure virtual (powerup), just want to style on 'em
	
//hitbox
	//virtual void getHB(float &x, float &y, float &w, float &h);
	//virtual void getTexture(float &r, float &g, float &b);
	//virtual void draw();
	virtual ~Object();
	};


#endif
