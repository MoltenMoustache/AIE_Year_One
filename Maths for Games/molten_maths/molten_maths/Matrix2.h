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
		float m_data1D[4];
	};
	Matrix2(Vector2 a_xAxis, Vector2 a_yAxis) : xAxis(a_xAxis), yAxis(a_yAxis) {};
	Matrix2(const float a_x1 = 1.0f, const float a_x2 = 0.0f,
			const float a_y1 = 0.0f, const float a_y2 = 1.0f)
			: xAxis(Vector2(a_x1, a_x2)), 
			yAxis(Vector2(a_y1, a_y2)) {};

	const Matrix2 identity() const;

	Vector2& operator[] (int a_index);

	operator float* ();
	operator const float*() const;

	Matrix2 operator * (const Matrix2& a_other) const;

	Vector2 operator * (const Vector2& a_other) const;

	Matrix2 Transposed() const;

	// Matrix + Matrix
	Matrix2 operator + (const Matrix2& a_other) const;

	// Matrix - Matrix
	Matrix2 operator - (const Matrix2& a_other) const;

	// Matrix + Scalar
	Matrix2 operator + (const int& a_scalar) const;

	// Matrix - Scalar
	Matrix2 operator - (const int& a_scalar) const;

	void setScaled(const float a_xScale, const float a_yScale);
	void setScaled(const Vector2& a_vec);

	void setRotateX(float a_rotation);
	void setRotateY(float a_rotation);
};