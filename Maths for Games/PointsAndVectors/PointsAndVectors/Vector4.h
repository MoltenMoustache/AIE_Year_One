#pragma once
#include <assert.h>
#include <math.h>

class Vector4
{
public:
	Vector4(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f, const float a_w = 1.0f) :x(a_x), y(a_y), z(a_z), w(a_w) {};
	~Vector4() {};

	// Vector Subscript Operator
	float& operator[] (const int a_index) {
		assert((a_index >= 0) && (a_index < 4) && "Vector4 index out of range!");
		return m_data[a_index];
	}

	// Vector Cast Operator
	operator float* () {
		return m_data;
	}

	// Vector Cast Operator
	operator const float*() const {
		return m_data;
	}

	// Anonymous structs, all structs share the same memory address
	union {
		// X, Y, Z coordinates
		struct {
			float x, y, z, w;
		};

		// Array of float
		float m_data[4];
	};

	// Vector + Vector
	Vector4 operator+(const Vector4& a_rhs) const {
		return Vector4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
	}

	// Vector - Vector
	Vector4 operator-(const Vector4& a_rhs) const {
		return Vector4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
	}

	// Vector * Vector
	Vector4 operator*(const Vector4& a_rhs) const
	{
		return Vector4(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z);
	}

	// Vector / Vector
	Vector4 operator/ (const Vector4& a_rhs) const {
		return Vector4(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z);
	}

	// Vector += Vector
	Vector4& operator += (const Vector4& a_other) {
		x += a_other.x, y += a_other.y, z += a_other.z;
		return *this;
	}

	// Vector *= Vector
	Vector4& operator *= (const Vector4& a_other) {
		x *= a_other.x, y *= a_other.y, z *= a_other.z;
		return *this;
	}
	// Vector -= Vector
	Vector4 operator -= (const Vector4 a_other) {
		x -= a_other.x, y -= a_other.y, z -= a_other.z;
		return *this;
	}

	// Vector = Vector
	Vector4 operator = (const Vector4& a_other) {
		x = a_other.x, y = a_other.y, z = a_other.z, w = a_other.w;
		return *this;
	}

	// Vector /= Float
	Vector4& operator /= (float a_scalar)
	{
		x /= a_scalar, y /= a_scalar, z /= a_scalar;
		return *this;
	}

	// Vector *= float
	Vector4& operator *= (float a_scalar) {
		x *= a_scalar, y *= a_scalar, z *= a_scalar;
		return *this;
	}

	// Vector += float
	Vector4& operator += (float a_scalar) {
		x += a_scalar, y += a_scalar, z += a_scalar;
		return *this;
	}

	// Vector == Vector
	bool operator == (const Vector4& a_other) {
		return ((x == a_other.x) && y == (a_other.y) && (z == a_other.z) && (w == a_other.w));
	}

	// Vector != Vector
	bool operator != (const Vector4& a_other) {
		/*if (x == a_other.x && y == a_other.y && z == a_other.z) {
			return false;
		}
		else {
			return true;
		}*/

		return !((x == a_other.x) && (y == a_other.y) && (z == a_other.z) && (w == a_other.w));
	}

	// Returns the magnitude of this Vector
	float Magnitude() const { return sqrt(SqrMagnitude()); }

	float SqrMagnitude() const { return (x * x) + (y * y) + (z * z); }

	// Calculates distance between two Vectors
	float Distance(const Vector4 a_other) const {
		float diffX = x - a_other.x;
		float diffY = y - a_other.y;
		float diffZ = z - a_other.z;
		return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
	}

	// Normalises this Vector
	void Normalise() {
		*this /= Magnitude();
	}

	// Returns a normalised version of this Vector
	Vector4 Normalised() const {
		return *this / Magnitude();
	}

	// Calclates the dot product
	float Dot(const Vector4& a_other) const {
		return x * a_other.x + y * a_other.y + z * a_other.z;
	}

	// Finding crossover
	Vector4 Cross(const Vector4& a_other) const {
		return { y * a_other.z - z * a_other.y,
				 z * a_other.x - x * a_other.z,
				 x * a_other.y - y * a_other.x };
	}

	float FindAngle(const Vector4& a_other) const {
		// Normalises the vectors
		Vector4 a = Normalised();
		Vector4 b = a_other.Normalised();

		// calculates dot product and returns the angle between vectors
		return acos(Dot(a_other));
	}

	// Returns a vector made of the largest components of two vectors
	Vector4 Max(const Vector4& a_other) {
		return Vector4(maxVal(x, a_other.x), maxVal(y, a_other.y), maxVal(z, a_other.z), maxVal(w, a_other.w));
	}
	// Returns a vector made of the smallest components of two vectors
	Vector4 Min(const Vector4& a_other) {
		return Vector4(minVal(x, a_other.x), minVal(y, a_other.y), minVal(z, a_other.z), minVal(w, a_other.w));
	}

private:

	// Finds the max value between two floats
	float maxVal(float a_lhs, float a_rhs) {

		// if the left hand side float is larger than the right hand side float
		if (a_lhs > a_rhs) {
			// return the left hand side
			return a_lhs;
		}
		else {
			// otherwise, return the right hand side (returns a_rhs even if both values are the same)
			return a_rhs;
		}
	}

	// Finds the min value between two floats
	float minVal(float a_lhs, float a_rhs) {
		// if the left hand side float is smaller than the right hand side float
		if (a_lhs < a_rhs) {
			// return the left hand side
			return a_lhs;
		}
		else {
			// otherwise, return the right hand side (returns a_rhs even if both values are the same)
			return a_rhs;
		}
	}
};

