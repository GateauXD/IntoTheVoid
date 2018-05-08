#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

class TexRect {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
    int rows;
    int cols;
    int curr_row;
    int curr_col;
    bool animating;
    bool complete;


    TexRect (const char*, float, float, float, float);
    TexRect (const char*, const char*, int, int, float, float, float, float);

    void draw();
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);

    void jump();
    void animate();
    void advance();
    void reset();
    
    //void jump();
    
    void getPosition(float x,float y);
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);

    float getWidth() const;
    float getHeight() const;

    bool rising;
    bool movingLeft;

    float xinc;
    float yinc;
};

#endif
