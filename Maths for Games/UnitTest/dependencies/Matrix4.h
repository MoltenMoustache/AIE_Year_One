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
		float m_data1D[16];
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

	// Produces an identity matrix
	const Matrix4 identity() const;

	// sub-script operator
	Vector4& operator[] (int a_index);

	operator float* ();
	operator const float*() const;

	// Matrix4 operator *
	Matrix4 operator* (const Matrix4& a_other) const;

	// Vector4 operator *
	Vector4 operator* (const Vector4& a_other) const;

	// Transposed()
	Matrix4 Transposed() const;

	// Matrix + Matrix
	Matrix4 operator + (const Matrix4& a_other) const;

	// Matrix - Matrix
	Matrix4 operator - (const Matrix4& a_other) const;

	// Matrix + Scalar
	Matrix4 operator + (const int& a_scalar) const;

	// Matrix - Scalar
	Matrix4 operator - (const int& a_scalar) const;

	void setScaled(const float a_xScale, const float a_yScale, const float a_zScale, const float a_tScale);
	void setScaled(const Vector4& a_vec);

	void setRotateX(float a_rotation);
	void setRotateY(float a_rotation);
	void setRotateZ(float a_rotation);
};