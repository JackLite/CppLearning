#pragma once

class Matrix3x3 {
public:
	Matrix3x3(float* values);
	float determinant();
private:
	float* _values;
};