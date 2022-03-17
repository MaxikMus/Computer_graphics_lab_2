#include "hex.h"


HEX::HEX() {
	obj = new point[6];
	temp = new POINT[6];
	obj[0].x = 100;
	obj[0].y = 50;
	obj[1].x = 150;
	obj[1].y = 50;
	obj[2].x = 200;
	obj[2].y = 100;
	obj[3].x = 150;
	obj[3].y = 150;
	obj[4].x = 100;
	obj[4].y = 150;
	obj[5].x = 50;
	obj[5].y = 100;
}

HEX ::~HEX() {
	delete[] obj;
	delete[] temp;
}


void HEX::move(unsigned int axis, float speed) {
	switch (axis)
	{
	case 0:
		for (size_t i = 0; i < 6; i++) {
			obj[i].x += speed;
		}
		break;
		//по y
	case 1:
		for (size_t i = 0; i < 6; i++) {
			obj[i].y += speed;
		}
		break;
	default:
		break;
	}
}

void HEX::scale(float scale) {
	if (!(abs(obj[3].x - obj[0].x) < 1 && abs(obj[3].y - obj[0].y) < 1 && scale < 1)) {
		scale = ((scale - 1) / 2) + 1;
		float cX, cY;
		cX = (obj[0].x + obj[3].x) / 2;
		cY = (obj[0].y + obj[3].y) / 2;
		for (size_t i = 0; i < 6; i++) {
			obj[i].x = (obj[i].x - cX) * scale + cX;
			obj[i].y = (obj[i].y - cY) * scale + cY;
		}
	}
}

void HEX::rotate(double angle) {
	float cX, cY;
	cX = (obj[0].x + obj[3].x) / 2;
	cY = (obj[0].y + obj[3].y) / 2;

	float tempX;
	for (size_t i = 0; i < 6; i++) {
		tempX = obj[i].x;
		obj[i].x = (obj[i].x - cX) * cos(angle) - (obj[i].y - cY) * sin(angle) + cX;
		obj[i].y = (tempX - cX) * sin(angle) + (obj[i].y - cY) * cos(angle) + cY;
	}
}

POINT* HEX::getPoint() {
	for (size_t i = 0; i < 6; i++) {
		temp[i].x = static_cast<int>(obj[i].x);
		temp[i].y = static_cast<int>(obj[i].y);
	}
	return temp;
}

void showHex(POINT* obj, HDC hdc) {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, hPen);
	for (size_t i = 0, k = 1; i < 6; i++, k++) {
		MoveToEx(hdc, obj[i].x, obj[i].y, NULL);
		if (k == 6) k = 0;
		LineTo(hdc, obj[k].x, obj[k].y);
	}
}