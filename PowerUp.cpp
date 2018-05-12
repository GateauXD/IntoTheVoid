#include "PowerUp.h"

PowerUp::PowerUp()
{
	objectTex = new TexRect("images/mushroom.png", "images/exp2_0.png", 4, 4, 0, 0, 0.2, 0.2);
}

PowerUp::PowerUp(float x, float y)
{
	objectTex = new TexRect("images/mushroom.png", "images/exp2_0.png", 4, 4, x, y, 0.2, 0.2);
}

void PowerUp::draw()
{
	objectTex->draw();
}

PowerUp::~PowerUp() {}
