#include "Projectile.h"

Projectile::Projectile()
{
	objectTex = new TexRect("images/basicBullet.bmp", 0, 0, 0.025, 0.025);
}

Projectile::Projectile(float x, float y)
{
	objectTex = new TexRect("images/basicBullet.bmp", x, y, 0.025, 0.025);
}

void Projectile::draw()
{
	objectTex->draw();
}

Projectile::~Projectile() {}