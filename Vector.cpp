#define _USE_MATH_DEFINES
#include "Vector.h"
#include "Matrix.h"
#include <math.h>

Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector::magnitude()
{
	return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::cross(const Vector& v)
{
	auto cx = y * v.z - z * v.y;
	auto cy = z * v.x - x * v.z;
	auto cz = x * v.y - y * v.x;
	return Vector(cx, cy, cz);
}

bool Vector::isOrthogonal(Vector& v)
{
	if (isZeroVector() || v.isZeroVector())
		return false;
	return std::abs(*this * v) < VECTOR_EPSILON;
}

bool Vector::isCollinear(Vector& v)
{
	if (isZeroVector() || v.isZeroVector())
		return true;
	if (std::abs(x) < VECTOR_EPSILON && std::abs(v.x) > VECTOR_EPSILON)
		return false;

	if (std::abs(v.x) < VECTOR_EPSILON && std::abs(x) > VECTOR_EPSILON)
		return false;

	if (std::abs(y) < VECTOR_EPSILON && std::abs(v.y) > VECTOR_EPSILON)
		return false;

	if (std::abs(v.y) < VECTOR_EPSILON && std::abs(y) > VECTOR_EPSILON)
		return false;

	if (std::abs(z) < VECTOR_EPSILON && std::abs(v.z) > VECTOR_EPSILON)
		return false;

	if (std::abs(v.z) < VECTOR_EPSILON && std::abs(z) > VECTOR_EPSILON)
		return false;

	auto checkX = std::abs(x) < VECTOR_EPSILON && std::abs(v.x) < VECTOR_EPSILON;
	auto checkY = std::abs(y) < VECTOR_EPSILON && std::abs(v.y) < VECTOR_EPSILON;
	auto checkZ = std::abs(z) < VECTOR_EPSILON && std::abs(v.z) < VECTOR_EPSILON;

	float xp = 0.0f;
	float yp = 0.0f;
	float zp = 0.0f;

	if(!checkX)
		xp = x / v.x;
	if(!checkY)
		yp = y / v.y;
	if(!checkZ)
		zp = z / v.z;
	return (checkX || checkY || std::abs(xp - yp) < VECTOR_EPSILON)
		&& (checkY || checkZ || std::abs(yp - zp) < VECTOR_EPSILON);
}

bool Vector::isZeroVector()
{
	return std::abs(x) < VECTOR_EPSILON
		&& std::abs(y) < VECTOR_EPSILON
		&& std::abs(z) < VECTOR_EPSILON;
}

float vectorAngle(Vector& v1, Vector& v2)
{
	float cos = (v1 * v2) / (v1.magnitude() * v2.magnitude());
	constexpr float rad2Deg = 180 / static_cast<float>(M_PI);
	return std::acos(cos) * rad2Deg;
}

Vector operator+(const Vector& v1, const Vector& v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector operator-(const Vector& v1, const Vector& v2)
{
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector operator*(const Vector& v, const float s)
{
	return Vector(v.x * s, v.y * s, v.z * s);
}

float operator*(const Vector& v1, const Vector& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

bool operator==(const Vector& v1, const Vector& v2)
{
	return std::abs(v1.x - v2.x) < VECTOR_EPSILON
		&& std::abs(v1.y - v2.y) < VECTOR_EPSILON
		&& std::abs(v1.z - v2.z) < VECTOR_EPSILON;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "X: " << v.x << "; Y: " << v.y << "; Z: " << v.z;
	return os;
}
