/*=============================
	 J O S H		M O T E N
  =============================

	File: main.cpp
	Date Modified: 19/2/2019

	Modifications:
	- Started and finished solution.
  =============================*/


#include <iostream>
#include <ctime>

using namespace std;
const int ARRAY_SIZE = 100;
bool BinarySearch(int a_arr[], const int a_array_length, int a_first_guess, int& loops);
void GuessNumber(int guess);
char GetInput();
void NumberGuessed();


int main() {

	int turns = 0;
	int numbers[ARRAY_SIZE];
	int guessedNumber = 0;

	cout << "Think of a number between 1 and 100 and press 'Enter' when you are ready.\n";
	system("pause");

	srand(time(nullptr));
	guessedNumber = (rand() % ARRAY_SIZE + 1);


	while (!BinarySearch(numbers, ARRAY_SIZE, guessedNumber, turns)) {
		BinarySearch(numbers, ARRAY_SIZE, guessedNumber, turns);
	}


	cout << "Ah-ha! I guessed your number in " << (turns + 1) << " guesses!\n";
	system("pause");

}

bool BinarySearch(int a_arr[], const int a_array_length, int a_first_guess, int& loops) {
	int min = 0;
	int max = ARRAY_SIZE;
	int mid = a_first_guess;
	bool isFound = false;

	GuessNumber(a_first_guess);
	while (!isFound) {
		switch (GetInput()) {
		case '>':
			max = (mid - 1);
			mid = ((min + max) / 2);
			GuessNumber(mid);
			break;
		case '<':
			min = (mid + 1);
			mid = ((min + max) / 2);
			GuessNumber(mid);
			break;
		case '=':
			isFound = true;
			return true;
			break;
		}

		loops++;
	}



}

char GetInput() {
	char op;

	cout << "Use the '>', '<', and '=' operators to answer.\n";
	cin >> op;


	if (cin.fail()) {
		cout << "Error!\n";
		system("pause");
		GetInput();
	}

	return op;
}

void GuessNumber(int guess) {
	cout << "Is " << guess << " higher, lower or equal to your number?\n";
}

void NumberGuessed() {
}