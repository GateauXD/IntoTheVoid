#ifndef SHAPE_H
#define SHAPE_H

#include <stdlib.h> //rand()
#include <time.h> //time()

class Shape{

protected:
	float x, y, red, green, blue;

public:
	Shape(){
		x = 0.0;
		y = 0.0;
		//red = (float)(rand() % 100) / 100;		// float between 0 and 1
		//green = (float)(rand() % 100) / 100;
		//blue = (float)(rand() % 100) / 100;
		red=1;
		blue=1;
		green=1;
	}

	Shape(float x, float y){
		this->x = x;
		this->y = y;
		//red = (float)(rand() % 100) / 100;		// float between 0 and 1
		//green = (float)(rand() % 100) / 100;
		//blue = (float)(rand() % 100) / 100;
		red=1;
		blue=1;
		green=1;
	}

	float getRed() const{
		return red;
	}
	float getGreen() const{
		return green;
	}
	float getBlue() const{
		return blue;
	}
	
	void setX(float x){
		this->x = x;
	}
	void setY(float y){
		this->y = y;
	}
	float getX() const{
		return x;
	}
	float getY() const{
		return y;
	}
	// PROXY, WILL FIX/REPLACE
	virtual float getWidth() const{ return 0; }
	virtual float getHeight() const{  return 0; }
	
	virtual void getPosition(float &xx, float &yy) = 0; // could return a Vec

	virtual bool contains(float x, float y) = 0;

	virtual ~Shape(){}
};

#endif
