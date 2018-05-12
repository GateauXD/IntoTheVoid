#ifndef PowerUp_h
#define PowerUp_h

#include "Object.h"

class PowerUp : public Object {

public:
	PowerUp();
	PowerUp(float x, float y);
	
	void draw();
	
	~PowerUp();

};

#endif
