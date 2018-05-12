#ifndef OBJECT_H
#define OBJECT_H

#include "TexRect.h"

class Object {
protected:
	TexRect* objectTex;
    float speed;

public:
	float getSpeed() const;
	virtual TexRect* getHB() const;
	
	virtual bool checkCollision( Object &obj );
	virtual float getX();
	virtual float getY();
	virtual float getW();
	virtual float getH();
	virtual void movePos(unsigned char key); // may not need pure virtual (powerup), just want to style on 'em
	virtual void draw()=0;

	virtual ~Object();
};


#endif