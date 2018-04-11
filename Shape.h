#ifndef SHAPE_H
#define SHAPE_H

class Shape{

protected:
	float x,y,red, green, blue;

public:
	Shape(){
		x = 0.0;
		y = 0.0;
		red = (float)(rand() % 100) / 100;		// float between 0 and 1
		green = (float)(rand() % 100) / 100;
		blue = (float)(rand() % 100) / 100;
	}

	Shape(float x, float y){
		this->x = x;
		this->y = y;
		red = (float)(rand() % 100) / 100;		// float between 0 and 1
		green = (float)(rand() % 100) / 100;
		blue = (float)(rand() % 100) / 100;
	}

	float getX() const{
		return x;
	}
	float getY() const{
		return y;
	}
	void setX(float x){
		this->x = x;
	}
	void setY(float y){
		this->y = y;
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


	virtual bool contains(float x, float y) = 0;

	~Shape(){}
};

#endif