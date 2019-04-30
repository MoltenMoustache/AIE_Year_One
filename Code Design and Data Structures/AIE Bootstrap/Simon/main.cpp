#include "SimonApp.h"
#include <crtdbg.h>

int main() {
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	
	// allocation
	auto app = new SimonApp();

	// initialise and loop
	app->run("Simeon Says", 720, 500, false);

	// deallocation
	delete app;

	return 0;
}