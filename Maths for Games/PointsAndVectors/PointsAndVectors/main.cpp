#include <iostream>
#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"
#include "Matrix3.h"

// prints the x, y, z variables of the passed in vector
// Vector3
void PrintVector(Vector3 a_vec)
{
	std::cout << a_vec.x << ", " << a_vec.y << ", " << a_vec.z << std::endl;
}

// Overload for Vector2
void PrintVector(Vector2 a_vec)
{
	std::cout << a_vec.x << ", " << a_vec.y << std::endl;
}

// Overload for Vector4
void PrintVector(Vector4 a_vec)
{
	std::cout << a_vec.x << ", " << a_vec.y << ", " << a_vec.z << ", " << a_vec.w << std::endl;
}

int main() {
	Matrix3 matrix = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
	

	



	system("pause");
}