#include "Matrix3.h"

Matrix3::Matrix3(const float a_x1, const float a_x2, const float a_x3, const float a_y1, const float a_y2, const float a_y3, const float a_z1, const float a_z2, const float a_z3)
	: xAxis(Vector3(a_x1, a_x2, a_x3)),
	yAxis(Vector3(a_y1, a_y2, a_y3)),
	zAxis(Vector3(a_z1, a_z2, a_z3)) 
	//m_data1D{ a_x1, a_x2, a_x3 , a_y1, a_y2, a_y3, a_z1, a_z2, a_z3 }
{}

const Matrix3 Matrix3::identity() const {
	return Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

Vector3& Matrix3::operator[] (int a_index) {
	return axis[a_index];
}

// Cast Operator
Matrix3::operator float* () {
	return m_data1D;
}

// Cast Operator
Matrix3::operator const float*() const {
	return m_data1D;
}

// Matrix * Matrix
Matrix3 Matrix3::operator * (const Matrix3& a_other) const {
	return
	{
		m_data[0][0] * a_other.m_data[0][0] + m_data[1][0] * a_other.m_data[0][1] + m_data[2][0] * a_other.m_data[0][2], // First line
		m_data[0][1] * a_other.m_data[0][0] + m_data[1][1] * a_other.m_data[0][1] + m_data[2][1] * a_other.m_data[0][2], // Expand to 1 column
		m_data[0][2] * a_other.m_data[0][0] + m_data[1][2] * a_other.m_data[0][1] + m_data[2][2] * a_other.m_data[0][2], // 33%

		m_data[0][0] * a_other.m_data[1][0] + m_data[1][0] * a_other.m_data[1][1] + m_data[2][0] * a_other.m_data[1][2], // Moving accress RHS columns
		m_data[0][1] * a_other.m_data[1][0] + m_data[1][1] * a_other.m_data[1][1] + m_data[2][1] * a_other.m_data[1][2],
		m_data[0][2] * a_other.m_data[1][0] + m_data[1][2] * a_other.m_data[1][1] + m_data[2][2] * a_other.m_data[1][2], // 66%

		m_data[0][0] * a_other.m_data[2][0] + m_data[1][0] * a_other.m_data[2][1] + m_data[2][0] * a_other.m_data[2][2], // Moving accress RHS columns
		m_data[0][1] * a_other.m_data[2][0] + m_data[1][1] * a_other.m_data[2][1] + m_data[2][1] * a_other.m_data[2][2],
		m_data[0][2] * a_other.m_data[2][0] + m_data[1][2] * a_other.m_data[2][1] + m_data[2][2] * a_other.m_data[2][2] // 100%

	};
}

// Matrix * Vector
Vector3 Matrix3::operator * (const Vector3& a_other) const {
	return
	{
		m_data[0][0] * a_other[0] + m_data[1][0] * a_other[1] + m_data[2][0] * a_other[2],
		m_data[0][1] * a_other[0] + m_data[1][1] * a_other[1] + m_data[2][1] * a_other[2],
		m_data[0][2] * a_other[0] + m_data[1][2] * a_other[1] + m_data[2][2] * a_other[2],
	};
}

// Matrix + Matrix
Matrix3 Matrix3::operator + (const Matrix3& a_other) const {
	Matrix3 result;

	for (size_t row = 0; row < 3; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			result.m_data[col][row] += a_other.m_data[col][row];
		}
	}

	return result;
}

// Matrix + Scalar
Matrix3 Matrix3::operator + (const int& a_scalar) const {
	Matrix3 result;

	for (size_t row = 0; row < 3; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			result.m_data[col][row] += a_scalar;
		}
	}

	return result;
}

// Matrix - Matrix
Matrix3 Matrix3::operator - (const Matrix3& a_other) const {
	Matrix3 result;

	for (size_t row = 0; row < 3; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			result.m_data[col][row] -= a_other.m_data[col][row];
		}
	}

	return result;
}

// Matrix - Scalar
Matrix3 Matrix3::operator - (const int& a_scalar) const {
	Matrix3 result;

	for (size_t row = 0; row < 3; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			result.m_data[col][row] -= a_scalar;
		}
	}

	return result;
}

Matrix3 Matrix3::Transposed() const {
	Matrix3 result;

	// flip row and column
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			result.m_data[row][col] = m_data[col][row];
		}
	}

	return result;
}

void Matrix3::setScaled(const float a_xScale, const float a_yScale, const float a_zScale) {
	// sets the scale of each axis
	xAxis = { a_xScale, 0, 0 };
	yAxis = { 0, a_yScale, 0 };
	zAxis = { 0, 0, a_zScale };
}

void Matrix3::setScaled(const Vector3& a_vec) {
	// sets the scale of each axis
	xAxis = { a_vec.x, 0, 0 };
	yAxis = { 0, a_vec.y, 0 };
	zAxis = { 0, 0, a_vec.z };
}

void Matrix3::scale(const float a_xScale, const float a_yScale, const float a_zScale) {
	Matrix3 result;
	result.setScaled(a_xScale, a_yScale, a_zScale);
	*this = *this * result;
}
void Matrix3::scale(const Vector3& a_vec) {
	Matrix3 result;
	result.setScaled(a_vec.x, a_vec.y, a_vec.z);
	*this = *this * result;
}

void Matrix3::setRotateX(float a_rotation) {

	m_data[1][1] = cos(a_rotation);
	m_data[2][1] = -sin(a_rotation);
	m_data[1][2] = sin(a_rotation);
	m_data[2][2] = cos(a_rotation);
}

void Matrix3::setRotateY(float a_rotation) {

	m_data[0][0] = cos(a_rotation);
	m_data[2][0] = sin(a_rotation);
	m_data[0][2] = -sin(a_rotation);
	m_data[2][2] = cos(a_rotation);
}

void Matrix3::setRotateZ(float a_rotation) {\

	m_data[0][0] = cos(a_rotation);
	m_data[1][0] = -sin(a_rotation);
	m_data[0][1] = sin(a_rotation);
	m_data[1][1] = cos(a_rotation);
}