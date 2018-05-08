#ifndef Score_h
#define Score_h

#include <string>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Score {
	unsigned score;
    float x;
    float y;
public:
    Score(){
        x = 0;
        y = 0;
		score = 0;
    }
    
	// (0.7, 0.9) is classic top-right corner
    Score(double x, double y){
        this->x = x;
        this->y = y;
		score = 0;
	}
	
    float getX() const { return x; } 
    float getY() const { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
	
	unsigned getScore() const { return score; }
    std::string getScoreString() const { return std::to_string(score); }
	
	// call during(after?) collision to add points to score
	void add(int points) { 
		score += points;
	}
	
	// call at beginning of drawing loop to put on top
	void draw() {
		glColor3d(1.0, 1.0, 0.0);
		glRasterPos2f(x, y);
		
		std::string s = std::to_string(score);
		const char* c = s.c_str();
		glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)c );

	}
};

#endif
