#ifndef RECT_H
#define RECT_H

#include <stdlib.h> //rand()
#include <time.h> //time()
#include "Shape.h"

class Rect: public Shape {
	float width, height;

public:
	Rect(): Shape(){
		width = 1.0f;
		height = 1.0f;
	}
	Rect(float x, float y, float width, float height): Shape(x,y){
		this->width = width;
		this->height = height;
	}

	~Rect() {}
	
	void setWidth(float w) {
		width = w;
	}
	void setHeight(float h) {
		height = h;
	}
	
	float getWidth() {
		return width;
	}
	float getHeight() {
		return height;
	}
	
	bool contains(float xx, float yy) {
		if (xx > x && xx < x + width) {
			if (yy < y && yy > y - height)
				return true;
		}
		return false;
	}
};

#endif