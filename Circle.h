#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath> //generateCircleData()
#include <vector>
#include "Shape.h"

//TODO: remove use of Vec
class Circle : public Shape {

protected:
	std::vector<Vec*>& points;
	Vec* center;
	float radius;
	int resolution;

public:
	Circle(): Shape(){
		center = new Vec(0,0);
		radius = 1.0f;
		resolution = 10;
		
		generateCircleData();
	}
	Circle(float x, float y, float radius, int resolution): Shape(){
		center = new Vec(x,y);
		this->radius = radius;
		this->resolution = resolution;
		
		generateCircleData();
	}

	~Circle() {
		delete center;
		for (unsigned i = 0; i < points.size(); i++) {
			delete points.at(i);
		}
	}
	
	void setCenter(float x, float y) {
		center->setX(x);
		center->setY(y);
	}
	void setRadius(float r) {
		radius = r;
	}
	void setResolution(int r) {
		resolution = r;
	}
	void getCenter(float &xx, float &yy) { // redundant
		xx = center->getX();
		yy = center->getY();
	}
	float getRadius() const{
		return radius;
	}
	int getResolution() const{
		return resolution;
	}
	void getPoints() const{
		return points;
	}
	
	void getPosition(float &xx, float &yy) {
		xx = center->getX();
		yy = center->getY();
	}
	
//	NOT DONE
	bool contains(float xx, float yy) {
		return false;
	}
	
	void generateCircleData() {
		points.clear();
		
		const double PI = 3.1415926535897932385;
		
		for (int i = 0; i < resolution; i++) {
			double theta = (2 * PI * i) / resolution;
			double x = radius * cos(theta) + center.getX();
			double y = radius * sin(theta) + center.getY();
			
			Vec *v = new Vec(x, y);
			points.push_back(v);
		}
	}
};

class Vec {
    float x, y;
    
public:
    Vec (){
        x = 0;
        y = 0;
    }   
    Vec (double x, double y){
        this->x = x;
        this->y = y;
    }
    
    float getX() const { return x; }
    float getY() const { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
};

#endif