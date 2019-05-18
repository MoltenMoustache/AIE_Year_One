#pragma once
#include <assert.h>
#include <math.h>

class Vector3
{
public:
	Vector3(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f) :x(a_x), y(a_y), z(a_z) {};

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
			float x, y, z;
		};

		// R, G, B colour variables
		struct {
			float r, g, b;
		};

		// Array of float
		float m_data[3];
	};

	// Vector + Vector
	Vector3 operator+(const Vector3& a_rhs) const;

	// Vector - Vector
	Vector3 operator-(const Vector3& a_rhs) const;

	// Vector * Vector
	Vector3 operator*(const Vector3& a_rhs) const;

	// Vector * float
	Vector3 operator*(const float& a_scalar) const;

	// Vector / Vector
	Vector3 operator/ (const Vector3& a_rhs) const;

	// Vector += Vector
	Vector3& operator += (const Vector3& a_other);

	// Vector *= Vector
	Vector3& operator *= (const Vector3& a_other);
	// Vector -= Vector
	Vector3 operator -= (const Vector3 a_other);

	// Vector /= Float
	Vector3& operator /= (float a_scalar);

	// Vector *= float
	Vector3& operator *= (float a_scalar);

	// Vector += float
	Vector3& operator += (float a_scalar);

	// Vector == Vector
	bool operator == (const Vector3& a_other);

	// Vector != Vector
	bool operator != (const Vector3& a_other);

	// Returns the magnitude of this Vector
	float magnitude() const;

	float SqrMagnitude() const;

	// Calculates distance between two Vectors
	float Distance(const Vector3 a_other) const;

	// Normalises this Vector
	void normalise();

	// Returns a normalised version of this Vector
	Vector3 Normalised() const;

	// Calclates the dot product
	float dot(const Vector3& a_other) const;

	// Finding crossover
	Vector3 cross(const Vector3& a_other) const;

	float FindAngle(const Vector3& a_other) const;

	// Returns a vector made of the largest components of two vectors
	Vector3 Max(const Vector3& a_other);
	// Returns a vector made of the smallest components of two vectors
	Vector3 Min(const Vector3& a_other);

private:
	float maxVal(float a_lhs, float a_rhs);

	float minVal(float a_lhs, float a_rhs);
};

Vector3 operator * (const float& a_lhs, const Vector3& a_rhs);

