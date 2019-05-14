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

	Matrix4() {};
	~Matrix4() {};

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
};