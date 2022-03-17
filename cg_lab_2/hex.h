#pragma once
#ifndef HEX_H
#define HEX_H

#include <windows.h>
#include <cmath>
#define PI 3.14159265358979323846
#define gradToRad(x) x * PI/180 

struct point {
	float x, y;
};

class HEX {
public:
	HEX ();
	~HEX ();
	void move(unsigned int axis, float speed);
	void rotate(double angle);
	void scale(float scale);
	POINT* getPoint();
	
private:
	point* obj = nullptr;
	POINT* temp = nullptr;
};

void showHex(POINT* obj, HDC hdc);



#endif // !HEX_H
