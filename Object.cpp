#include "Object.h"
float Object::getSpeed() const 
{ 
	return Object::speed; 
}

TexRect* Object::getHB() const 
{ 
	return Object::objectTex;
}

 bool Object::checkCollision(float x, float y) 
{
	return Object::objectTex->contains(x,y);
}

bool Object::checkCollision( Object &obj ) 
{
	return Object::objectTex->contains(obj->getHB()->getX(),obj->getHB()->getY()) || Object::objectTex->contains(obj->getHB()->getX() + obj->getHB()->getWidth(), obj->getHB()->getY()) || Object::objectTex->contains(obj->getHB()->getX() + obj->getHB()->getWidth(),obj->getHB()->getY() - obj->getHB()->getHeight()) || Object::objectTex->contains(obj->getHB()->getX(),obj->getHB()->getY() - obj->getHB()->getHeight());
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