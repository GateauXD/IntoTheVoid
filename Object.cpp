
#include "Object.h"
float Object::getSpeed() const 
{ 
	return Object::speed; 
}

 bool Object::checkCollision(float x, float y) 
{
	return Object::objectTex->contains(x,y);
}

 void Object::getPosition(float &x, float &y)
{ // could return a Vec
	Object::objectTex->getPosition(x, y);
}

//void Object::draw
//{

//}


 Object::~Object() 
{
	delete Object::objectTex;
}
