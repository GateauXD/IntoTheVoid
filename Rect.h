#ifndef RECT_H
#define RECT_H

#include <stdlib.h> //rand()
#include <time.h> //time()

class Rect {
	float x, y, width, height, red, green, blue;

public:
	Rect() {
		x = 0.0f;
		y = 0.0f;
		width = 1.0f;
		height = 1.0f;
		red = (float)(rand() % 100) / 100;		// float between 0 and 1
		green = (float)(rand() % 100) / 100;
		blue = (float)(rand() % 100) / 100;
	}
	Rect(float x, float y, float width, float height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		red = (float)(rand() % 100) / 100;
		green = (float)(rand() % 100) / 100;
		blue = (float)(rand() % 100) / 100;
	}
	~Rect() {}
	
	void setX(float xx) {
		x = xx;
	}
	void setY(float yy) {
		y = yy;
	}
	void setWidth(float w) {
		width = w;
	}
	void setHeight(float h) {
		height = h;
	}
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	float getWidth() {
		return width;
	}
	float getHeight() {
		return height;
	}
	float getRed() {
		return red;
	}
	float getGreen() {
		return green;
	}
	float getBlue() {
		return blue;
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