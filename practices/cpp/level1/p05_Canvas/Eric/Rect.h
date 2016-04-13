#ifndef RECT_H
#define RECT_H
#include <iostream>
#include "Sharp.h"

class Rect : public Sharp
{
public:
	Rect() = default;
	Rect(int x, int y, int len, int wid) : Sharp(x, y), width(wid), length(len){}
	void print() const override;
private:
	int length = 0;
	int width  = 0;
};
void Rect::print() const
{
	std::cout << "Rect " << locationX << "," << locationY << " length : " << length << " width : " << width << std::endl;
}
#endif