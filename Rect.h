#ifndef RECT_H
#define RECT_H

#include "Shape.h"
#include "TexRect.h"

class Rect: public Shape {
	float width, height;
	//TexRect* objectTex;

public:
	Rect(): Shape(){
		width = 1.0f;
		height = 1.0f;
	}
	Rect(float x, float y, float width, float height): Shape(x, y){
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
	float getWidth() const{
		return width;
	}
	float getHeight() const{
		return height;
	}
	
	void getPosition(float &xx, float &yy) {
		xx = x + width / 2;
		yy = y + height / 2;
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
