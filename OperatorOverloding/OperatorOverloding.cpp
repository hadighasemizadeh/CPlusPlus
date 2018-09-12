// OperatorOverloding.cpp : main project file.

#include <string>
#include <iostream>

using namespace std;
using namespace System;

class Circle
{
public:
	Circle();
	Circle(float radius);
	Circle(const Circle& rhs);

	void Display();

	double getRedius()const;
	double getArea()const;

	Circle operator+ (const Circle& rhs);
	Circle operator- (const Circle& rhs);

	Circle operator++();
	Circle operator++(int);

	bool operator>(const Circle&);
	bool operator<(const Circle&);
	bool operator>=(const Circle&);
	bool operator<=(const Circle&);
	bool operator==(const Circle&);
	bool operator!=(const Circle&);

	Circle& operator=(const Circle&);

private:
	double radius;

	friend istream& operator>>(istream&, Circle&);
};

Circle::Circle()
{
	this->radius = 0;
}

Circle::Circle(float radius)
{
	this->radius = radius;
}

// Copy constructor
Circle::Circle(const Circle& rhs)
{
	this->radius = rhs.radius;
}

void Circle::Display()
{
	cout << "Radius: " << radius << ", Area: " << getArea() << endl;
}

double Circle::getRedius() const
{
	return this->radius;
}

double Circle::getArea() const
{
	return 3.14159 * this->radius * this->radius;
}

Circle Circle::operator+ (const Circle& rhs) {
	Circle mc;
	mc.radius = this->radius + rhs.radius;
	return mc;
}

Circle Circle::operator-(const Circle& rhs) {
	Circle mc;
	mc.radius = this->radius - rhs.radius;
	return mc;
}

// Prefix ++
Circle Circle::operator++() {
	Circle cm;
	this->radius += 1;
	cm.radius = this->radius;
	return cm;
}

// Postfix ++
Circle Circle::operator++(int) {
	Circle cm;
	cm.radius = this->radius;
	this->radius += 1;
	return cm;
}

ostream& operator<< (ostream& sout, const Circle& c) {
	sout << "Radius is " << c.getRedius() << " and Area is " << c.getArea();
	return sout;
}

istream& operator>> (istream& sin, Circle& c) {
	sin >> c.radius;
	return sin;
}

bool Circle::operator>(const Circle& rhs) {
	return this->radius > rhs.getRedius();
}

bool Circle::operator<(const Circle& rhs) {
	return this->radius < rhs.radius;
}

bool Circle::operator>=(const Circle& rhs) {
	return this->radius >= rhs.getRedius();
}

bool Circle::operator<=(const Circle& rhs) {
	return this->radius <= rhs.radius;
}

bool Circle::operator==(const Circle& rhs) {
	return this->radius == rhs.radius;
}

bool Circle::operator!=(const Circle& rhs) {
	return this->radius != rhs.radius;
}

Circle& Circle::operator=(const Circle& rhs) {
	this->radius = rhs.radius;
	return *this;
}

int main()
{
	Circle c(0), c3(3), c4(4), c1(5), c2(10);

	//Circle c3 = c1 + c2;
	//c3.Display();

	/*********************************************/

	////c = ++c3;
	//c = c3++;

	//c3.Display();
	//c.Display();

	/*********************************************/
	//// Overload << example
	//cout << c4;

	//// Overload >> example
	//cin >> c;
	//c.Display();

	/*********************************************/

	// Overload >
	cout << (c3 > c4);

	return 0;
}
