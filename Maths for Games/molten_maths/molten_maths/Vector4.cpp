#include "Vector4.h"

float& Vector4::operator[] (const int a_index) {
	assert((a_index >= 0) && (a_index < 4) && "Vector4 index out of range!");
	return m_data[a_index];
}

// Vector Cast Operator
Vector4::operator float* () {
	return m_data;
}

// Vector Cast Operator
Vector4::operator const float*() const {
	return m_data;
}

// Vector + Vector
Vector4 Vector4::operator+(const Vector4& a_rhs) const {
	return Vector4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

// Vector - Vector
Vector4 Vector4::operator-(const Vector4& a_rhs) const {
	return Vector4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
}

// Vector * Vector
Vector4 Vector4::operator*(const Vector4& a_rhs) const
{
	return Vector4(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z, w * a_rhs.w);
}


Vector4 Vector4::operator*(const float& a_scalar) const {
	return Vector4(x * a_scalar, y * a_scalar, z * a_scalar, w * a_scalar);
}

// Vector / Vector
Vector4 Vector4::operator/ (const Vector4& a_rhs) const {
	return Vector4(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z);
}

// Vector += Vector
Vector4& Vector4::operator += (const Vector4& a_other) {
	x += a_other.x, y += a_other.y, z += a_other.z;
	return *this;
}

// Vector *= Vector
Vector4& Vector4::operator *= (const Vector4& a_other) {
	x *= a_other.x, y *= a_other.y, z *= a_other.z;
	return *this;
}
// Vector -= Vector
Vector4 Vector4::operator -= (const Vector4 a_other) {
	x -= a_other.x, y -= a_other.y, z -= a_other.z;
	return *this;
}

// Vector /= Float
Vector4& Vector4::operator /= (float a_scalar)
{
	x /= a_scalar, y /= a_scalar, z /= a_scalar;
	return *this;
}

// Vector *= float
Vector4& Vector4::operator *= (float a_scalar) {
	x *= a_scalar, y *= a_scalar, z *= a_scalar;
	return *this;
}

// Vector += float
Vector4& Vector4::operator += (float a_scalar) {
	x += a_scalar, y += a_scalar, z += a_scalar;
	return *this;
}

bool Vector4::operator == (const Vector4& a_other) {
	return ((x == a_other.x) && y == (a_other.y) && (z == a_other.z) && (w == a_other.w));
}

bool Vector4::operator != (const Vector4& a_other) {
	return !((x == a_other.x) && (y == a_other.y) && (z == a_other.z) && (w == a_other.w));
}

float Vector4::magnitude() const { return sqrt(SqrMagnitude()); }
float Vector4::SqrMagnitude() const { return (x * x) + (y * y) + (z * z); }

float Vector4::Distance(const Vector4 a_other) const {
	float diffX = x - a_other.x;
	float diffY = y - a_other.y;
	float diffZ = z - a_other.z;
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

void Vector4::normalise() {
	*this /= magnitude();
}

Vector4 Vector4::Normalised() const {
	return *this / magnitude();
}

float Vector4::dot(const Vector4& a_other) const {
	return x * a_other.x + y * a_other.y + z * a_other.z;
}

Vector4 Vector4::cross(const Vector4& a_other) const {
	return { y * a_other.z - z * a_other.y,
			 z * a_other.x - x * a_other.z,
			 x * a_other.y - y * a_other.x, w };
}

float Vector4::FindAngle(const Vector4& a_other) const {
	// Normalises the vectors
	Vector4 a = Normalised();
	Vector4 b = a_other.Normalised();

	// calculates dot product and returns the angle between vectors
	return acos(dot(a_other));
}

Vector4 Vector4::Max(const Vector4& a_other) {
	return Vector4(maxVal(x, a_other.x), maxVal(y, a_other.y), maxVal(z, a_other.z), maxVal(w, a_other.w));
}
// Returns a vector made of the smallest components of two vectors
Vector4 Vector4::Min(const Vector4& a_other) {
	return Vector4(minVal(x, a_other.x), minVal(y, a_other.y), minVal(z, a_other.z), minVal(w, a_other.w));
}

float Vector4::maxVal(float a_lhs, float a_rhs) {

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

float Vector4::minVal(float a_lhs, float a_rhs) {
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

Vector4 operator*(const float & a_lhs, const Vector4 & a_rhs)
{
	return a_rhs * a_lhs;
}
