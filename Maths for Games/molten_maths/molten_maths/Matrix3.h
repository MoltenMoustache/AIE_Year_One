#pragma once
#include "Vector3.h"

class Matrix3 {
public:

	// Constructor for 3x Vectors
	Matrix3(Vector3 a_xAxis, Vector3 a_yAxis, Vector3 a_zAxis) : xAxis(a_xAxis), yAxis(a_yAxis), zAxis(a_zAxis) {};

	// Constructor for 9x floats
	Matrix3(const float a_x1 = 1.0f, const float a_x2 = 0.0f, const float a_x3 = 0.0f,
			const float a_y1 = 0.0f, const float a_y2 = 1.0f, const float a_y3 = 0.0f,
			const float a_z1 = 0.0f, const float a_z2 = 0.0f, const float a_z3 = 1.0f);

	union {
		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		Vector3 axis[3];
		float m_data[3][3];
		float m_data1D[9];
	};

	const Matrix3 identity() const;

	Vector3& operator[] (int a_index);

	operator float* ();
	operator const float*() const;

	// Matrix * Matrix
	Matrix3 operator * (const Matrix3& a_other) const;

	// Matrix * Vector
	Vector3 operator * (const Vector3& a_other) const;

	// Matrix + Matrix
	Matrix3 operator + (const Matrix3& a_other) const;

	// Matrix + Scalar
	Matrix3 operator + (const int& a_scalar) const;

	// Matrix - Matrix
	Matrix3 operator - (const Matrix3& a_other) const;
	
	// Matrix - Scalar
	Matrix3 operator - (const int& a_scalar) const;

	Matrix3 Transposed() const;

	void setScaled(const float a_xScale, const float a_yScale, const float a_zScale);
	void setScaled(const Vector3& a_vec);

	void scale(const float a_xScale, const float a_yScale, const float a_zScale);
	void scale(const Vector3& a_vec);

	void setRotateX(float a_rotation);
	void setRotateY(float a_rotation);
	void setRotateZ(float a_rotation);
};