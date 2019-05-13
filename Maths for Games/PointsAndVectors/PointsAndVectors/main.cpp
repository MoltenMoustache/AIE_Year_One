#include <iostream>
#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"

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
	Vector3 blankVector;								// Empty vector {0.0f, 0.0f, 0.0f}
	Vector3 playerPos{ 1.0f, 4.5f, 1.0f };
	Vector3 playerOffset{ 2.0f, 0.0f, 5.0f };

	Vector3 maxPlayerPos = playerPos.Max(playerOffset);
	Vector3 minPlayerPos = playerPos.Min(playerOffset);
	PrintVector(maxPlayerPos);
	PrintVector(minPlayerPos);

	



	system("pause");
}