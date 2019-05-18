#include "Vector2.h"

// Vector Subscript Operator
float& Vector2::operator[] (const int a_index) {
	assert((a_index >= 0) && (a_index < 2) && "Vector2 index out of range!");
	return m_data[a_index];
}

// Vector Cast Operator
Vector2::operator float* () {
	return m_data;
}

// Vector Cast Operator
Vector2::operator const float*() const {
	return m_data;
}

// Vector + Vector
Vector2 Vector2::operator+(const Vector2& a_rhs) const {
	return Vector2(x + a_rhs.x, y + a_rhs.y);
}

// Vector - Vector
Vector2 Vector2::operator-(const Vector2& a_rhs) const {
	return Vector2(x - a_rhs.x, y - a_rhs.y);
}

// Vector * Vector
Vector2 Vector2::operator*(const Vector2& a_rhs) const {
	return Vector2(x * a_rhs.x, y * a_rhs.y);
}

// Vector * float
Vector2 Vector2::operator*(const float& a_scalar) const {
	return Vector2(x * a_scalar, y * a_scalar);
}

// Vector / Vector
Vector2 Vector2::operator/ (const Vector2& a_rhs) const {
	return Vector2(x / a_rhs.x, y / a_rhs.y);
}

// Vector += Vector
Vector2& Vector2::operator += (const Vector2& a_other) {
	x += a_other.x, y += a_other.y;
	return *this;
}

// Vector *= Vector
Vector2& Vector2::operator *= (const Vector2& a_other) {
	x *= a_other.x, y *= a_other.y;
	return *this;
}
// Vector -= Vector
Vector2 Vector2::operator -= (const Vector2 a_other) {
	x -= a_other.x, y -= a_other.y;
	return *this;
}

// Vector /= Float
Vector2& Vector2::operator /= (float a_scalar)
{
	assert(a_scalar <= 0 && "Can't divide by zero!");
	x /= a_scalar, y /= a_scalar;
	return *this;
}

// Vector *= float
Vector2& Vector2::operator *= (float a_scalar) {
	x *= a_scalar, y *= a_scalar;
	return *this;
}

// Vector += float
Vector2& Vector2::operator += (float a_scalar) {
	x += a_scalar, y += a_scalar;
	return *this;
}

// Vector == Vector
bool Vector2::operator == (const Vector2& a_other) {
	if (x == a_other.x && y == a_other.y) {
		return true;
	}
	else {
		return false;
	}
}

// Vector != Vector
bool Vector2::operator != (const Vector2& a_other) {
	if (x == a_other.x && y == a_other.y) {
		return false;
	}
	else {
		return true;
	}
}

float Vector2::magnitude() const { return sqrt(x * x + y * y); }

// Calculates distance between two Vectors
float Vector2::Distance(const Vector2 a_other) const {
	float diffX = x - a_other.x;
	float diffY = y - a_other.y;
	return sqrt(diffX * diffX + diffY * diffY);
}

// Normalises this Vector
void Vector2::normalise() {
	float magnitude = sqrt(x * x + y * y);
	x /= magnitude;
	y /= magnitude;
}

// Returns a normalised version of this Vector
Vector2 Vector2::Normalised() const {
	float magnitude = sqrt(x * x + y * y);
	return Vector2(x / magnitude, y / magnitude);
}

float Vector2::dot(const Vector2& a_other) const {
	return x * a_other.x + y * a_other.y;
}

// Returns a vector made of the largest components of two vectors
Vector2 Vector2::Max(const Vector2& a_other) {
	return Vector2(maxVal(x, a_other.x), maxVal(y, a_other.y));
}
// Returns a vector made of the smallest components of two vectors
Vector2 Vector2::Min(const Vector2& a_other) {
	return Vector2(minVal(x, a_other.x), minVal(y, a_other.y));
}
float Vector2::maxVal(float a_lhs, float a_rhs) {
	if (a_lhs > a_rhs) {
		return a_lhs;
	}
	else {
		return a_rhs;
	}
}

float Vector2::minVal(float a_lhs, float a_rhs) {
	if (a_lhs < a_rhs) {
		return a_lhs;
	}
	else {
		return a_rhs;
	}
}

Vector2 operator*(const float& a_lhs, const Vector2 & a_rhs)
{
	return a_rhs * a_lhs;
}