#include "Powerup.h"

Powerup::Powerup()
{
	speed=0;
	objectTex= new TexRect("assets/basicBullet.png",0,0,0.1,0.1);
}

Powerup::Powerup(int x,int y)
{
	speed=0;
	objectTex= new TexRect("assets/basicBullet.png",0,0,0.1,0.1);
}

void Powerup::movePos(unsigned char key)
{

}

void Powerup::draw()const
{
	objectTex->draw();
}

void Powerup::speedup(int& speed)
{
	speed++;
}
Powerup::~Powerup()
{

}
