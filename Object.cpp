#include "Object.h"
float Object::getSpeed() const 
{ 
	return Object::speed; 
}

TexRect* Object::getHB() const 
{ 
	return Object::objectTex;
}

bool Object::checkCollision( Object &obj ) 
{
	return Object::objectTex->contains(obj.getHB()->getX(),obj.getHB()->getY()) || Object::objectTex->contains(obj.getHB()->getX() + obj.getHB()->getW(), obj.getHB()->getY()) || Object::objectTex->contains(obj.getHB()->getX() + obj.getHB()->getW(),obj.getHB()->getY() - obj.getHB()->getH()) || Object::objectTex->contains(obj.getHB()->getX(),obj.getHB()->getY() - obj.getHB()->getH());
}

float Object::getX()
{
	return Object::objectTex->getX();
}

float Object::getY()
{
	return Object::objectTex->getY();
}

float Object::getW()
{
	return Object::objectTex->getW();
}

float Object::getH()
{
	return Object::objectTex->getH();
}

//void Object::draw
//{

//}


 Object::~Object() 
{
	delete Object::objectTex;
}
