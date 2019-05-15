#include "unittest.h"
#include <iostream>
#include "Matrix3.h"
#include "Vector3.h"

int main() {

	
	Matrix3 result;
	Vector3 scalar(3.0f, 3.0f, 3.0f);

	Matrix3 someMatrix = { 1, 2, 3, 1, 2, 3, 2, 3, 4 };

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	return 0;
}