#include "Matrix4.h"

// Produces an identity matrix
const Matrix4 Matrix4::identity() const {
	return Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

// sub-script operator
Vector4& Matrix4::operator[] (int a_index) {
	return axis[a_index];
}

// Cast Operator
Matrix4::operator float* () {
	return m_data1D;
}

// Cast Operator
Matrix4::operator const float*() const {
	return m_data1D;
}

// Matrix4 operator *
Matrix4 Matrix4::operator* (const Matrix4& a_other) const {
	Matrix4 result;

	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result[col][row] = m_data[0][row] * a_other.m_data[col][0] +
							   m_data[1][row] * a_other.m_data[col][1] +
							   m_data[2][row] * a_other.m_data[col][2] +
							   m_data[3][row] * a_other.m_data[col][3];
		}
	}

	return result;
}

// Vector4 operator *
Vector4 Matrix4::operator* (const Vector4& a_other) const {
	Vector4 result;

	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result[row] = m_data[0][row] * a_other[0] +
						  m_data[1][row] * a_other[1] +
						  m_data[2][row] * a_other[2] +
						  m_data[3][row] * a_other[3];
		}
	}

	return result;
}

// Transposed()
Matrix4 Matrix4::Transposed() const {
	Matrix4 result;

	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result[row][col] = m_data[col][row];
		}
	}

	return result;
}

// Matrix + Matrix
Matrix4 Matrix4::operator + (const Matrix4& a_other) const {
	Matrix4 result;

	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result.m_data[col][row] += a_other.m_data[col][row];
		}
	}

	return result;
}

// Matrix - Matrix
Matrix4 Matrix4::operator - (const Matrix4& a_other) const {
	Matrix4 result;

	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result.m_data[col][row] -= a_other.m_data[col][row];
		}
	}

	return result;
}

// Matrix + Scalar
Matrix4 Matrix4::operator + (const int& a_scalar) const {
	Matrix4 result;

	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result.m_data[col][row] += a_scalar;
		}
	}

	return result;
}

// Matrix - Scalar
Matrix4 Matrix4::operator - (const int& a_scalar) const {
	Matrix4 result;

	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			result.m_data[col][row] -= a_scalar;
		}
	}

	return result;
}


void Matrix4::setScaled(const float a_xScale, const float a_yScale, const float a_zScale, const float a_tScale) {
	// sets the scale of each axis
	xAxis = { a_xScale, 0, 0 };
	yAxis = { 0, a_yScale, 0 };
	zAxis = { 0, 0, a_zScale };
	tAxis = { 0, 0, a_tScale };
}

void Matrix4::setScaled(const Vector4& a_vec) {
	// sets the scale of each axis
	xAxis = { a_vec.x, 0, 0, 0};
	yAxis = { 0, a_vec.y, 0, 0};
	zAxis = { 0, 0, a_vec.z, 0 };
	tAxis = { 0, 0, 0, a_vec.w };
}

void Matrix4::setRotateX(float a_rotation) {

	*this = identity();

	m_data[1][1] = cos(a_rotation);
	m_data[2][1] = -sin(a_rotation);
	m_data[1][2] = sin(a_rotation);
	m_data[2][2] = cos(a_rotation);
}

void Matrix4::setRotateY(float a_rotation) {

	*this = identity();

	m_data[0][0] = cos(a_rotation);
	m_data[2][0] = sin(a_rotation);
	m_data[0][2] = -sin(a_rotation);
	m_data[2][2] = cos(a_rotation);
}

void Matrix4::setRotateZ(float a_rotation) {

	*this = identity();

	m_data[0][0] = cos(a_rotation);
	m_data[1][0] = -sin(a_rotation);
	m_data[0][1] = sin(a_rotation);
	m_data[1][1] = cos(a_rotation);
}