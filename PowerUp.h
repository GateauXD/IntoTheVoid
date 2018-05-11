#ifndef PowerUp_h
#define PowerUp_h
#include <vector>
//#include "TexRect.h"
#include "GlutApp.h"
#include <stdlib.h>
#include <time.h>
#include "App.h"

#include "Object.h"

class PowerUp : public Object {
	//TexRect* tex;
	int* x;
	int* y;
public:

	PowerUp();
	void draw();
	void animate();
	TexRect getTex();
	int getX();
	int getY();
	bool collision(TexRect player); // returns true if collision is detected.
	~PowerUp();

};

#endif
