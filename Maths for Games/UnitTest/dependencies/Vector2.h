#pragma once
#include <assert.h>
#include <math.h>

class Vector2
{
public:
	Vector2() : x(0.0f), y(0.0f) {};
	Vector2(const float a_x, const float a_y) :x(a_x), y(a_y) {};

	// Vector Subscript Operator
	float& operator[] (const int a_index);

	// Vector Cast Operator
	operator float* ();

	// Vector Cast Operator
	operator const float*() const;

	// Anonymous structs, all structs share the same memory address
	union {
		// X, Y, Z coordinates
		struct {
			float x, y;
		};

		// Array of float
		float m_data[3];
	};

	// Vector + Vector
	Vector2 operator+(const Vector2& a_rhs) const;

	// Vector - Vector
	Vector2 operator-(const Vector2& a_rhs) const;

	// Vector * Vector
	Vector2 operator*(const Vector2& a_rhs) const;

	// Vector * float
	Vector2 operator*(const float& a_scalar) const;

	// Vector / Vector
	Vector2 operator/ (const Vector2& a_rhs) const;

	// Vector += Vector
	Vector2& operator += (const Vector2& a_other);

	// Vector *= Vector
	Vector2& operator *= (const Vector2& a_other);
	// Vector -= Vector
	Vector2 operator -= (const Vector2 a_other);

	// Vector /= Float
	Vector2& operator /= (float a_scalar);

	// Vector *= float
	Vector2& operator *= (float a_scalar);

	// Vector += float
	Vector2& operator += (float a_scalar);

	// Vector == Vector
	bool operator == (const Vector2& a_other);

	// Vector != Vector
	bool operator != (const Vector2& a_other);

	float magnitude() const;

	// Calculates distance between two Vectors
	float Distance(const Vector2 a_other) const;

	// Normalises this Vector
	void normalise();

	// Returns a normalised version of this Vector
	Vector2 Normalised() const;

	// Calclates the dot product
	float dot(const Vector2& a_other) const;

	// Returns a vector made of the largest components of two vectors
	Vector2 Max(const Vector2& a_other);
	// Returns a vector made of the smallest components of two vectors
	Vector2 Min(const Vector2& a_other);

private:
	float maxVal(float a_lhs, float a_rhs);

	float minVal(float a_lhs, float a_rhs);
};

Vector2 operator * (const float& a_lhs, const Vector2& a_rhs);

