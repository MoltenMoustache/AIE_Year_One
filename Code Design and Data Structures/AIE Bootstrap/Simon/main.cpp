#include "SimonApp.h"

int main() {
	
	// allocation
	auto app = new SimonApp();

	// initialise and loop
	app->run("Simeon Says", 720, 500, false);

	// deallocation
	delete app;

	return 0;
}