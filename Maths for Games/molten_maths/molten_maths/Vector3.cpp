#include "Vector3.h"

// Vector Subscript Operator
float& Vector3::operator[] (const int a_index) {
	assert((a_index >= 0) && (a_index < 3) && "Vector3 index out of range!");
	return m_data[a_index];
}

// Vector Cast Operator
Vector3::operator float* () {
	return m_data;
}

// Vector Cast Operator
Vector3::operator const float*() const {
	return m_data;
}

// Vector + Vector
Vector3 Vector3::operator+(const Vector3& a_rhs) const {
	return Vector3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

// Vector - Vector
Vector3 Vector3::operator-(const Vector3& a_rhs) const {
	return Vector3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
}

// Vector * Vector
Vector3 Vector3::operator*(const Vector3& a_rhs) const
{
	return Vector3(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z);
}

// Vector * float
Vector3 Vector3::operator*(const float& a_rhs) const {
	return Vector3(x * a_rhs, y * a_rhs, z * a_rhs);
}

// Vector / Vector
Vector3 Vector3::operator/ (const Vector3& a_rhs) const {
	return Vector3(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z);
}

// Vector += Vector
Vector3& Vector3::operator += (const Vector3& a_other){
	x += a_other.x, y += a_other.y, z += a_other.z;
	return *this;
}

// Vector *= Vector
Vector3& Vector3::operator *= (const Vector3& a_other) {
	x *= a_other.x, y *= a_other.y, z *= a_other.z;
	return *this;
}
// Vector -= Vector
Vector3 Vector3::operator -= (const Vector3 a_other) {
	x -= a_other.x, y -= a_other.y, z -= a_other.z;
	return *this;
}

// Vector /= Float
Vector3& Vector3::operator /= (float a_scalar)
{
	x /= a_scalar, y /= a_scalar, z /= a_scalar;
	return *this;
}

// Vector *= float
Vector3& Vector3::operator *= (float a_scalar) {
	x *= a_scalar, y *= a_scalar, z *= a_scalar;
	return *this;
}

// Vector += float
Vector3& Vector3::operator += (float a_scalar) {
	x += a_scalar, y += a_scalar, z += a_scalar;
	return *this;
}

// Vector == Vector
bool Vector3::operator == (const Vector3& a_other) {
	return ((x == a_other.x) && y == (a_other.y) && (z == a_other.z));
}

// Vector != Vector
bool Vector3::operator != (const Vector3& a_other) {
	/*if (x == a_other.x && y == a_other.y && z == a_other.z) {
		return false;
	}
	else {
		return true;
	}*/

	return !((x == a_other.x) && y == (a_other.y) && (z == a_other.z));
}

// Returns the magnitude of this Vector
float Vector3::magnitude() const { return sqrt(SqrMagnitude()); }

float Vector3::SqrMagnitude() const { return (x * x) + (y * y) + (z * z); }

// Calculates distance between two Vectors
float Vector3::Distance(const Vector3 a_other) const {
	float diffX = x - a_other.x;
	float diffY = y - a_other.y;
	float diffZ = z - a_other.z;
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

// Normalises this Vector
void Vector3::normalise() {
	*this /= magnitude();
}

// Returns a normalised version of this Vector
Vector3 Vector3::Normalised() const {
	return *this / magnitude();
}

// Calclates the dot product
float Vector3::dot(const Vector3& a_other) const {
	return x * a_other.x + y * a_other.y + z * a_other.z;
}

// Finding crossover
Vector3 Vector3::cross(const Vector3& a_other) const {
	return { y * a_other.z - z * a_other.y,
			 z * a_other.x - x * a_other.z,
			 x * a_other.y - y * a_other.x };
}

float Vector3::FindAngle(const Vector3& a_other) const {
	// Normalises the vectors
	Vector3 a = Normalised();
	Vector3 b = a_other.Normalised();

	// calculates dot product and returns the angle between vectors
	return acos(dot(a_other));
}

// Returns a vector made of the largest components of two vectors
Vector3 Vector3::Max(const Vector3& a_other) {
	return Vector3(maxVal(x, a_other.x), maxVal(y, a_other.y), maxVal(z, a_other.z));
}
// Returns a vector made of the smallest components of two vectors
Vector3 Vector3::Min(const Vector3& a_other) {
	return Vector3(minVal(x, a_other.x), minVal(y, a_other.y), minVal(z, a_other.z));
}

float Vector3::maxVal(float a_lhs, float a_rhs) {
	if (a_lhs > a_rhs) {
		return a_lhs;
	}
	else {
		return a_rhs;
	}
}

float Vector3::minVal(float a_lhs, float a_rhs) {
	if (a_lhs < a_rhs) {
		return a_lhs;
	}
	else {
		return a_rhs;
	}
}

Vector3 operator*(const float & a_lhs, const Vector3 & a_rhs)
{
	return a_rhs * a_lhs;
}
