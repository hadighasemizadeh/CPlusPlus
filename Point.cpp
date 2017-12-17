#include "stdafx.h"
#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(float f_x, float f_y, float f_z) {
	cout << "We are setting variables with constructor" << endl;
	x = f_x;
	y = f_y;
	z = f_z;
}

Point::~Point() {
	cout << "Instance of the class was destructed." << endl;
}

void Point::GetXYZ(float &_X, float &_Y, float &_Z) {
	_X = GetX();
	_Y = GetY();
	_Z = GetZ();
}

float Point::GetX() {
	return x;
}

float Point::GetY() {
	return y;
}

float Point::GetZ() {
	return z;
}

void Point::SetXYZ(float _X, float _Y, float _Z) {
	SetX(_X);
	SetY(_Y);
	SetZ(_Z);
}

void Point::SetX(float _X) {
	x = _X;
}

void Point::SetY(float _Y) {
	y = _Y;
}

void Point::SetZ(float _Z) {
	z = _Z;
}
// Override == operator for point class
Point Point::operator = (Point &p) {
	SetX(p.GetX());
	SetY(p.GetY());
	SetZ(p.GetZ());

	return *this;
}

// Stream a point
ostream &operator << (ostream &os, Point &p) {
	os << p.GetX() << " " << p.GetY() << " " << p.GetZ();
	return os;
}

istream &operator >> (istream &ist, Point &p) {
	float _x, _y, _z;
	ist >> _x >> _y >> _z;
	p.SetXYZ(_x, _y, _z);
	return ist;
}
