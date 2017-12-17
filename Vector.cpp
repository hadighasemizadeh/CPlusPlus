#include "stdafx.h"
#include "Vector.h"
#include "Point.h"
#include <iostream>
using namespace std;

Vector::Vector(float _x, float _y, float _z) : Point(_x, _y, _z)
{
}

Vector Vector::operator+ (Vector &p) {
	Vector outVector;
	outVector.SetX(GetX() + p.GetX());
	outVector.SetY(GetY() + p.GetY());
	outVector.SetZ(GetZ() + p.GetZ());

	return outVector;
}

Vector Vector::operator- (Vector &p) {
	Vector outVector;
	outVector.SetX(GetX() - p.GetX());
	outVector.SetY(GetY() - p.GetY());
	outVector.SetZ(GetZ() - p.GetZ());

	return outVector;
}

Vector Vector::operator* (float _scale) {
	Vector outVector;
	outVector.SetX(GetX()*_scale);
	outVector.SetY(GetY()*_scale);
	outVector.SetZ(GetZ()*_scale);

	return outVector;
}

Vector operator* (const float &_scale, Vector &v) {
	Vector outVector;
	outVector.SetX(v.GetX()*_scale);
	outVector.SetY(v.GetY()*_scale);
	outVector.SetZ(v.GetZ()*_scale);

	return outVector;
}
