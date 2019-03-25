#include <iostream>
#include "dynamic_array.h"

int main() {
	dynamic_array dynamArray;

	dynamArray.Push(10);
	dynamArray.Push(5);
	dynamArray.Push(23);

	dynamArray.Pop();
	dynamArray.Pop();

	return 0;
}