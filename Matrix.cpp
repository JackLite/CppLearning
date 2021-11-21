#include "Matrix.h";

Matrix3x3::Matrix3x3(float* values)
{
	_values = values;
}

float Matrix3x3::determinant()
{
	return
		_values[0] * _values[4] * _values[8] +
		_values[1] * _values[5] * _values[6] +
		_values[2] * _values[3] * _values[7] -
		_values[2] * _values[4] * _values[6] -
		_values[0] * _values[5] * _values[7] -
		_values[1] * _values[3] * _values[8];
}