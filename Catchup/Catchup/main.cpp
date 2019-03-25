#include <iostream>
// ENUMS
// NAMESPACES (using namespace 'X' = bad practice, allows ambiguity in code)
// --OPERATOR OVERLOADING-- ???
//


enum class BoysName : unsigned char {
	Adam = 0,
	Josh = 1,
	Max = 2,
	Seth = 3,
	Charlie = 4,
};

// the 'class' scopes the enum and the 'unsigned char' limits the size of the enum 
enum class GirlsName : unsigned char {
	Alanah = 0,
	Paige = 1,
	Charlie = 2,
};

// namespaces help compartmentalise functions, allowing multiple definitions of the same function from different namespaces
namespace test {

	enum class GirlsName : unsigned char {
		Alanah = 0,
		Paige = 1,
		Taite = 2,
		Charlie = 3,
	};
}

int main() {

	// Currently not required but good practice to use when using pointers
	// Creates a memory dump at build time to show any memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int x = int(GirlsName::Charlie);
	int y = int(BoysName::Charlie);
	int z = int(test::GirlsName::Charlie);
}

