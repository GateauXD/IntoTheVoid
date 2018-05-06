
#include "Object.h"
float Object::getSpeed() const 
{ 
	return Object::speed; 
}

 bool Object::checkCollision(float x, float y) 
{
	return Object::hitbox->contains(x,y);
}

 void Object::getPosition(float &x, float &y)
{ // could return a Vec
	Object::hitbox->getPosition(x, y);
}

 void Object::getHB(float &x, float &y, float &w, float &h) 
{
	x = Object::hitbox->getX();
	y = Object::hitbox->getY();
	w = Object::hitbox->getWidth();
	h = Object::hitbox->getHeight();
}

 void Object::getHBColor(float &r, float &g, float &b) 
{
	r = Object::hitbox->getRed();
	g = Object::hitbox->getGreen();
	b = Object::hitbox->getBlue();
}

//void Object::draw
//{

//}
 Object::~Object() 
{
	delete Object::hitbox;
	delete Object::objectTex;
}
