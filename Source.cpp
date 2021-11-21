#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include "Vector.h"
#include <math.h>
using namespace std::literals;
constexpr float deg2Rad = static_cast<float>(M_PI) / 180.0f;

int main()
{
	auto v1 = Vector(0.5, 0.5, 0);
	auto v2 = Vector(5, -5, 0);
	auto v1m = v1.magnitude();
	auto v2m = v2.magnitude();
	auto angle = vectorAngle(v1, v2);
	auto test = v1m * v2m * std::sinf(angle * deg2Rad);
	auto cross = v1.cross(v2);
	std::cout << "Angle "s << vectorAngle(v1, v2) << "\n";
	std::cout << "V1 magnitude "s << v1m << "\n";
	std::cout << "V2 magnitude "s << v2m << "\n";
	std::cout << "Cross v "s << cross << "\n";
	std::cout << "Cross 1 "s << cross.magnitude() << "\n";
	std::cout << "Cross 2 "s << test << "\n";
	std::cout << vectorAngle(cross, v1);
	return 0;
}