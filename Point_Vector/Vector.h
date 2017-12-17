#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

class Vector : public Point {
public:
	Vector(float _x = 0, float _y = 0, float _z = 0);
	Vector operator +(Vector &p);
	Vector operator -(Vector &p);
	Vector operator *(float scale);
};

#endif // !VECTOR_H
