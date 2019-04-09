#include <iostream>
#include "binary_tree.h"

int main() {

	binary_tree<int> binTree;
	binTree.insert(57);
	binTree.insert(6);
	binTree.insert(17);
	binTree.insert(39);
	if (binTree.find(17)) {
		std::cout << "FOUND!\n";
	}
	else {
		std::cout << "NOT FOUND!\n";
	}


	system("pause");
	return 0;
}