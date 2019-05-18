#pragma once
#include <assert.h>
#include <math.h>

class Vector4
{
public:
	Vector4(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f, const float a_w = 1.0f) :x(a_x), y(a_y), z(a_z), w(a_w) {};

	// Anonymous structs, all structs share the same memory address
	union {
		// X, Y, Z coordinates
		struct {
			float x, y, z, w;
		};

		// Array of float
		float m_data[4];
	};

	// Vector Subscript Operator
	float& operator[] (const int a_index);

	// Vector Cast Operator
	operator float* ();

	// Vector Cast Operator
	operator const float*() const;

	// Vector + Vector
	Vector4 operator+(const Vector4& a_rhs) const;

	// Vector - Vector
	Vector4 operator-(const Vector4& a_rhs) const;

	// Vector * Vector
	Vector4 operator*(const Vector4& a_rhs) const;

	// Vector * float
	Vector4 operator*(const float& a_scalar) const;

	// Vector / Vector
	Vector4 operator/ (const Vector4& a_rhs) const;

	// Vector += Vector
	Vector4& operator += (const Vector4& a_other);

	// Vector *= Vector
	Vector4& operator *= (const Vector4& a_other);

	// Vector -= Vector
	Vector4 operator -= (const Vector4 a_other);

	// Vector /= Float
	Vector4& operator /= (float a_scalar);

	// Vector *= float
	Vector4& operator *= (float a_scalar);

	// Vector += float
	Vector4& operator += (float a_scalar);

	// Vector == Vector
	bool operator == (const Vector4& a_other);

	// Vector != Vector
	bool operator != (const Vector4& a_other);

	// Returns the magnitude of this Vector
	float magnitude() const;

	float SqrMagnitude() const;

	// Calculates distance between two Vectors
	float Distance(const Vector4 a_other) const;

	// Normalises this Vector
	void normalise();

	// Returns a normalised version of this Vector
	Vector4 Normalised() const;

	// Calclates the dot product
	float dot(const Vector4& a_other) const;

	// Finding crossover
	Vector4 cross(const Vector4& a_other) const;

	float FindAngle(const Vector4& a_other) const;

	// Returns a vector made of the largest components of two vectors
	Vector4 Max(const Vector4& a_other);
	// Returns a vector made of the smallest components of two vectors
	Vector4 Min(const Vector4& a_other);

private:

	// Finds the max value between two floats
	float maxVal(float a_lhs, float a_rhs);

	// Finds the min value between two floats
	float minVal(float a_lhs, float a_rhs);
};

Vector4 operator * (const float& a_lhs, const Vector4& a_rhs);

