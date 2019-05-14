#pragma once
#include "Vector2.h"
class Matrix2 {
public:
	union {
		struct {
			Vector2 xAxis;
			Vector2 yAxis;
		};
		Vector2 axis[2];
		float m_data[2][2];
	};
	Matrix2(Vector2 a_xAxis, Vector2 a_yAxis) : xAxis(a_xAxis), yAxis(a_yAxis) {};
	Matrix2(float a_x1, float a_x2, float a_y1, float a_y2) : xAxis(Vector2(a_x1, a_x2)), yAxis(Vector2(a_y1, a_y2)) {};
	Matrix2() {};
	~Matrix2() {};

	Vector2& operator[] (int a_index) {
		return axis[a_index];
	}

	Matrix2 operator * (const Matrix2& a_other) const {
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

	Vector2 operator * (const Vector2& a_other) const {
		Vector2 result;

		for (size_t row = 0; row < 2; row++)
		{
			result[row] = m_data[0][row] * a_other[0] +
						  m_data[2][row] * a_other[2];
						  m_data[1][row] * a_other[1] +
		}

		return result;
	}

	Matrix2 Transposed() const {
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
};