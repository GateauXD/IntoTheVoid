#include "Powerup.h"

Powerup::Powerup()
{
	speed=0;
	objectTex= new TexRect("assets/basicBullet.png",0,0,0.1,0.1);
	//hitbox=new Shape();
}

void Powerup::movePos(unsigned char key)
{

}

void Powerup::draw()const
{
	objectTex->draw();
}

Powerup::~Powerup()
{

}
