#pragma once
#include "Vector3.h"

class Matrix3 {
public:

	// Constructor for 3x Vectors
	Matrix3(Vector3 a_xAxis, Vector3 a_yAxis, Vector3 a_zAxis) : xAxis(a_xAxis), yAxis(a_yAxis), zAxis(a_zAxis) {};

	// Constructor for 9x floats
	Matrix3(const float a_x1 = 1.0f, const float a_x2 = 0.0f, const float a_x3 = 0.0f,
			const float a_y1 = 0.0f, const float a_y2 = 1.0f, const float a_y3 = 0.0f,
			const float a_z1 = 0.0f, const float a_z2 = 0.0f, const float a_z3 = 1.0f)
			: xAxis(Vector3(a_x1, a_x2, a_x3)),
			yAxis(Vector3(a_y1, a_y2, a_y3)),
			zAxis(Vector3(a_z1, a_z2, a_z3)) {};
	~Matrix3() {};

	union {
		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		Vector3 axis[3];
		float m_data[3][3];
	};

	const Matrix3 identity() const {
		return Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	}

	Vector3& operator[] (int a_index) {
		return axis[a_index];
	}

	// Matrix * Matrix
	Matrix3 operator * (const Matrix3& a_other) const {
		Matrix3 result;

		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				result.m_data[column][row] = m_data[0][row] * a_other.m_data[column][0] +
											 m_data[1][row] * a_other.m_data[column][1] +
											 m_data[2][row] * a_other.m_data[column][2];
			}
		}

		return result;
	}

	// Matrix * Vector
	Vector3 operator * (const Vector3& a_other) const {
		Vector3 result;

		for (size_t row = 0; row < 3; row++)
		{
			result[row] = m_data[0][row] * a_other[0] +
						  m_data[1][row] * a_other[1] +
						  m_data[2][row] * a_other[2];
		}

		return result;
	}

	// Matrix + Matrix
	Matrix3 operator + (const Matrix3& a_other) const {
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
	Matrix3 operator + (const int& a_scalar) const {
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
	Matrix3 operator - (const Matrix3& a_other) const {
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
	Matrix3 operator - (const int& a_scalar) const {
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

	Matrix3 Transposed() const {
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

};