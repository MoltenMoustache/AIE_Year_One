#include "Matrix2.h"

const Matrix2 Matrix2::identity() const {
	return Matrix2(1, 0, 0, 1);
}

Vector2& Matrix2::operator[] (int a_index) {
	return axis[a_index];
}

// Cast Operator
Matrix2::operator float* () {
	return m_data1D;
}

// Cast Operator
Matrix2::operator const float*() const {
	return m_data1D;
}

Matrix2 Matrix2::operator * (const Matrix2& a_other) const {
	Matrix2 result;

	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			result[col][row] = m_data[0][row] * a_other.m_data[col][0] +
				m_data[1][row] * a_other.m_data[col][1];
		}
	}

	return result;
}

Vector2 Matrix2::operator * (const Vector2& a_other) const {
	Vector2 result;

	for (size_t row = 0; row < 2; row++)
	{
		result[row] = m_data[0][row] * a_other[0] +
					  m_data[2][row] * a_other[2];
					  m_data[1][row] * a_other[1];
	}

	return result;
}

Matrix2 Matrix2::Transposed() const {
	Matrix2 result;

	for (size_t row = 0; row < 2; row++)
	{
		for (size_t col = 0; col < 2; col++)
		{
			result[row][col] = m_data[col][row];
		}
	}

	return result;
}

// Matrix + Matrix
Matrix2 Matrix2::operator + (const Matrix2& a_other) const {
	Matrix2 result;

	for (size_t row = 0; row < 2; row++)
	{
		for (size_t col = 0; col < 2; col++)
		{
			result.m_data[col][row] += a_other.m_data[col][row];
		}
	}

	return result;
}

// Matrix - Matrix
Matrix2 Matrix2::operator - (const Matrix2& a_other) const {
	Matrix2 result;

	for (size_t row = 0; row < 2; row++)
	{
		for (size_t col = 0; col < 2; col++)
		{
			result.m_data[col][row] -= a_other.m_data[col][row];
		}
	}

	return result;
}

// Matrix + Scalar
Matrix2 Matrix2::operator + (const int& a_scalar) const {
	Matrix2 result;

	for (size_t row = 0; row < 2; row++)
	{
		for (size_t col = 0; col < 2; col++)
		{
			result.m_data[col][row] += a_scalar;
		}
	}

	return result;
}

// Matrix - Scalar
Matrix2 Matrix2::operator - (const int& a_scalar) const {
	Matrix2 result;

	for (size_t row = 0; row < 2; row++)
	{
		for (size_t col = 0; col < 2; col++)
		{
			result.m_data[col][row] -= a_scalar;
		}
	}

	return result;
}


void Matrix2::setScaled(const float a_xScale, const float a_yScale) {
	// sets the scale of each axis
	xAxis = { a_xScale, 0 };
	yAxis = { 0, a_yScale };
}

void Matrix2::setScaled(const Vector2& a_vec) {
	// sets the scale of each axis
	xAxis = { a_vec.x, 0 };
	yAxis = { 0, a_vec.y };
}

void Matrix2::setRotateX(float a_rotation) {

	m_data[0][0] = cos(a_rotation);
	m_data[1][0] = sin(a_rotation);
	m_data[0][1] = -sin(a_rotation);
	m_data[1][1] = cos(a_rotation);
}

void Matrix2::setRotateY(float a_rotation) {

	m_data[0][0] = cos(a_rotation);
	m_data[1][0] = sin(a_rotation);
	m_data[0][1] = -sin(a_rotation);
	m_data[1][1] = cos(a_rotation);
}