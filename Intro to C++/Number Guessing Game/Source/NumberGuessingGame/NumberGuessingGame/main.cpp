#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int ARRAY_SIZE = 100;
bool BinarySearch(int a_arr[], const int a_array_length, int a_first_guess, int& loops);
void GuessNumber(int guess);
void GuessNumber(int guess, int a_previousGuess);
char GetInput();
void NumberGuessed();


int main() {

	int turns = 0;
	int numbers[ARRAY_SIZE];
	int guessedNumber = 0;

	cout << "Think of a number between 1 and 100 and press 'Enter' when you are ready.\n";
	system("pause");

	srand(time(nullptr));
	guessedNumber = 50;// (rand() % ARRAY_SIZE + 1);


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
	int previousGuess = a_first_guess;

	GuessNumber(a_first_guess);
	while (!isFound) {
		switch (GetInput()) {
		case '>':
			max = (mid - 1);
			mid = ((min + max) / 2);
			GuessNumber(mid, previousGuess);
			previousGuess = mid;
			break;
		case '<':
			min = (mid + 1);
			mid = ((min + max) / 2);
			GuessNumber(mid, previousGuess);
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

void GuessNumber(int guess, int a_previousGuess) {
	if (guess == a_previousGuess) {
		cout << "You're a filthy rotten cheater!\n\n";
		system("pause");
		exit(0);
	}
	cout << "Is " << guess << " higher, lower or equal to your number?\n";
}

void NumberGuessed() {
}