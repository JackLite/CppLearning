#include <iostream>
#pragma once

constexpr auto VECTOR_EPSILON = 0.00000000001;

class Vector
{
public: 
	float x;
	float y;
	float z;
	Vector();
	Vector(float x, float y, float z);
	float magnitude();
	Vector cross(const Vector& v);
	bool isOrthogonal(Vector& v);
	bool isCollinear(Vector& v);
private:
	bool isZeroVector();
};

float vectorAngle(Vector& v1, Vector& v2);

Vector operator+(const Vector& v1, const Vector& v2);
Vector operator-(const Vector& v1, const Vector& v2);
Vector operator*(const Vector& v1, const float s);
float operator*(const Vector& v1, const Vector& v2);
bool operator==(const Vector& v1, const Vector& v2);
std::ostream& operator<<(std::ostream& os, const Vector& v);