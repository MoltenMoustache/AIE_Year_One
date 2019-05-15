#pragma once
#include "Vector4.h"
class Matrix4 {
public:
	union {
		struct {
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 tAxis;
		};
		Vector4 axis[4];
		float m_data[4][4];
	};

	// Constructor for 4x Vector4's
	Matrix4(Vector4 a_xAxis, Vector4 a_yAxis, Vector4 a_zAxis, Vector4 a_tAxis) : xAxis(a_xAxis), yAxis(a_yAxis), zAxis(a_zAxis), tAxis(a_tAxis) {};

	// Constructor for 16x Floats
	Matrix4(const float a_x1 = 1.0f, const float a_x2 = 0.0f, const float a_x3 = 0.0f, const float a_x4 = 0.0f,
			const float a_y1 = 0.0f, const float a_y2 = 1.0f, const float a_y3 = 0.0f, const float a_y4 = 0.0f,
			const float a_z1 = 0.0f, const float a_z2 = 0.0f, const float a_z3 = 1.0f, const float a_z4 = 0.0f,
			const float a_t1 = 0.0f, const float a_t2 = 0.0f, const float a_t3 = 0.0f, const float a_t4 = 1.0f)
			: xAxis(Vector4(a_x1, a_x2, a_x3, a_x4)),
			yAxis(Vector4(a_y1, a_y2, a_y3, a_y4)),
			zAxis(Vector4(a_z1, a_z2, a_z3, a_z4)),
			tAxis(Vector4(a_t1, a_t2, a_t3, a_t4)) {};

	Matrix4() {};
	~Matrix4() {};

	// Produces an identity matrix
	const Matrix4 identity() const {
		return Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	}

	// sub-script operator
	Vector4& operator[] (int a_index) {
		return axis[a_index];
	}

	// Matrix4 operator *
	Matrix4 operator* (const Matrix4& a_other) const {
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
	Vector4 operator* (const Vector4& a_other) const {
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
	Matrix4 Transposed() const {
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
	Matrix4 operator + (const Matrix4& a_other) const {
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
	Matrix4 operator - (const Matrix4& a_other) const {
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
	Matrix4 operator + (const int& a_scalar) const {
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
	Matrix4 operator - (const int& a_scalar) const {
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
};