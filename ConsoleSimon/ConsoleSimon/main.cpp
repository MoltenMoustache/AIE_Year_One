#include <iostream>
#include <ctime>
#include "linked_list.h"

#include <stdexcept>
enum Colour {
	Red,
	Green,
	Blue,
	Yellow,
	END,
};

void ClearBuffer();
void CheckInput();

std::istream& operator>> (std::istream& a_input, Colour& a_colour_input)
{
	int val;
	if (a_input >> val) {
		switch (val) {
		case Red: 
			a_colour_input = Colour(val);
			break;
		case Green: 
			a_colour_input = Colour(val);
			break;
		case Blue:
			a_colour_input = Colour(val);
			break;
		case Yellow:
			a_colour_input = Colour(val);
			break;
		default:
			throw std::out_of_range("Invalid value for type 'Colour'");
		}
	}
	return a_input;
}
std::ostream& operator<< (std::ostream& a_output, const Colour& a_colour_output)
{
	switch (a_colour_output) {
	case Red:
		a_output << "Red";
		break;
	case Blue:
		a_output << "Blue";
		break;
	case Green:
		a_output << "Green";
		break;
	case Yellow:
		a_output << "Yellow";
		break;
	}
	return a_output;
}

int main() {
	srand(time(nullptr));
	int counter = 0;
	bool game_over = false;
	linked_list<Colour> colours_shown;
	Colour first_colour = Colour(rand() % Colour::END);
	colours_shown.push_back(first_colour);
	colours_shown.display();

	while (!game_over) {
		counter++;
		std::cout << "=====================================\n" << "0 - Red, 1 - Green, 2 - Blue, 3 - Yellow\n\n";


		Colour input;
		std::cout << "Please press the correct buttons, in sequence.\n";
		std::cin >> input;
		ClearBuffer();
		if (colours_shown.check_input(input, counter)) {
			std::cout << "Correct!\n";
		}
		else {
			std::cout << "Incorrect...\n";
		}
		std::cout << input;
		system("pause");
		system("cls");

		Colour new_colour = Colour(rand() % Colour::END);
		colours_shown.push_back(new_colour);
		colours_shown.display();
	}
}

void ClearBuffer() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}