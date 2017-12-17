#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class  Point
{
public:
	Point(float f_x = 1.0, float f_y = 1.0, float f_z = 1.0);
	~Point();

	void SetXYZ(float _x, float _y, float _z);
	void SetX(float _x);
	void SetY(float _y);
	void SetZ(float _z);

	void GetXYZ(float &x, float &y, float &z);
	float GetX();
	float GetY();
	float GetZ();

	// Overloading an = operator
	Point operator = (Point &p);

private:
	float x, y, z;

protected:
};

ostream &operator << (ostream &os,  Point &p);

istream &operator >> (istream &ist, Point &p);
#endif // !POINT_H