#include "PowerUp.h"
PowerUp::PowerUp(App* a)
{
	*x = ((float)(rand() % 200) / 100)-1;
	*y = ((float)(rand() % 200) / 100)-1;
	tex=new TexRect("images/mushroom.png", "images/exp2_0.png", 4, 4, *x, *y, 0.2, 0.2);
	singleton = a;
}


void PowerUp::draw()
{
	this->tex->draw();

}

void PowerUp::animate()
{
	for(unsigned i = 0; i < singleton->Powerup.size(); i++)
		{
			float bx = singleton->Powerup.at(i)->x + singleton->Powerup.at(i)->w/2;
			float by = singleton->Powerup.at(i)->y - singleton->Powerup.at(i)->h + 0.1;
			if (singleton->platform->contains(bx, by))
			{
				singleton->score->add(50);
				delete singleton->Powerup.at(i);
				singleton->Powerup.erase(singleton->Powerup.begin() + i);
			}
		}

}


TexRect PowerUp::getTex()
{
	return *tex;

}

int PowerUp::getX()
{
	return *x;

}

int PowerUp::getY()
{
	return *y;

}

bool PowerUp::collision(TexRect player)
{
	float pX,pY,pH,pW;
	pX=player.getX();
	pY=player.getY();
	pH=player.getH();
	pW=player.getW();
	return (tex->contains(pX,pY)||tex->contains(pX,pY-pH)||tex->contains(pX+pW,pY)||tex->contains(pX+pW,pY-pH));

}

PowerUp::~PowerUp()
{
	delete tex;
	delete x;
	delete y;
}
