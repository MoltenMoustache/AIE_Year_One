#include "NewBinaryTreeApp.h"

int main() {
	
	// allocation
	auto app = new NewBinaryTreeApp();

	// initialise and loop
	app->run("Binary Tree", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}