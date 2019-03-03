/*=============================
	 J O S H		M O T E N
  =============================

	File: main.cpp
	Date Modified: 20/2/2019

	Modifications:
	- Additional comments
	- Sorting
  =============================*/

#include <iostream>
#include <ctime>
#include "Viking.h"

// constant variables
const int TEAM_SIZE = 2;

// function declarations
void ClearBuffer();
void AssignTeam(Viking team[]);
void DisplayTeams(Viking a_teamOne[], Viking a_teamTwo[]);
void Attack(Viking a_attackingViking, Viking a_attackingTeam[], Viking a_targetTeam[]);
void SelectAttacker(Viking a_attackingTeam[], Viking a_targetTeam[]);
bool CheckWin(Viking teamOne[], Viking teamTwo[]);
void Swap(Viking *xp, Viking *yp);
void BubbleSort(Viking teamOne[]);

using namespace std;



int main() {
	srand(time(nullptr));												// seeds the random function

	bool isGameOver = false;
	bool isTeamOnesTurn = true;											// handles which team is currently attacking
	Viking teamOne[TEAM_SIZE];											// team of Vikings
	Viking teamTwo[TEAM_SIZE];											// team of Vikings

	cout << "==\tVIKING BATTLE SIMULATOR\t==\n\n";
	cout << "=\tPlease enter details for Team One's Vikings.\t=\n";
	system("pause");
	AssignTeam(teamOne);												// calls the AssignTeam() function, passing in the first team as a parameter

	cout << "=\tPlease enter details for Team Two's Vikings.\t=\n";
	system("pause");
	AssignTeam(teamTwo);												// calls the AssignTeam() function, passing in the second team as a parameter

	DisplayTeams(teamOne, teamTwo);										// displays both teams after assignment

	while (!isGameOver) {												// game loop

		if (isTeamOnesTurn) {											// if it's team one's turn, attack team two and then flip the turn variable
			SelectAttacker(teamOne, teamTwo);
			isTeamOnesTurn = !isTeamOnesTurn;
		}
		else {															// if it's team two's turn, attack team two and then flip the turn variable
			SelectAttacker(teamTwo, teamOne);
			isTeamOnesTurn = !isTeamOnesTurn;
		}

		if (CheckWin(teamOne, teamTwo)) {								// checks if either team has been completely wiped out
			isGameOver = true;
		}
	}

	system("pause");
}

void AssignTeam(Viking team[]) {

	system("cls");														// clears the console

	for (size_t i = 0; i < TEAM_SIZE; i++)								// loops through the team members of the team passed into the function
	{
		cout << "Enter a name for this Viking: ";
		char input_name[BUFFER_LENGTH];
		cin.getline(input_name, BUFFER_LENGTH);							// accepts user input for viking name and stores in the 'input_name' variable
		cout << endl;

		system("cls");

		bool isValidInput = false;

		int input_health;
		while (!isValidInput) {											// for input validation
			cout << "Enter a health value for " << input_name << ": ";
			cin >> input_health;										// accepts user input for viking health and stores in the 'input_health' variable

			if (cin.fail()) {											// if the user input isn't an integer, continue the while loop
				cout << "Oops! That's not a number! Try again.\n";
				isValidInput = false;
			}
			else {														// if the user input is a valid integer, break the while loop
				isValidInput = true;
			}

			cout << endl;
			ClearBuffer();

			system("cls");
		}

		isValidInput = false;

		cout << "Enter a name for " << input_name << "'s attack: ";
		char input_attackName[BUFFER_LENGTH];
		cin.getline(input_attackName, BUFFER_LENGTH);					// accepts user input for the name of the viking's attack and stores in the 'input_attackName' variable
		cout << endl;

		system("cls");

		int input_attackValue;
		while (!isValidInput) {											// for input validation
			cout << "Enter a strength value for " << input_attackName << ": ";
			cin >> input_attackValue;									// accepts user input for viking's attack power and stores in the 'input_attackValue' variable

			if (cin.fail()) {											// if the user input isn't an integer, continue the while loop
				cout << "Oops! That's not a number! Try again.\n";
				isValidInput = false;
			}
			else {														// if the user input is a valid integer, break the while loop
				isValidInput = true;
			}
			cout << endl;

			system("cls");
			ClearBuffer();
		}

		//assigns all the inputted variables into the empty space in the viking team and then the for loop moves onto the next spot in the team to repeat the process
		team[i] = Viking(input_name, input_attackName, input_health, input_attackValue);
	}
}

void DisplayTeams(Viking a_teamOne[], Viking a_teamTwo[]) {
	system("cls");

	cout << "Team One" << "\t" << "Team Two\n";
	cout << "========================\n";

	// loops through all team members of both teams and displays the names of each member adjacent to the other team
	for (size_t index = 0; index < TEAM_SIZE; index++)
	{
		cout << a_teamOne[index].get_name() << "\t\t" << a_teamTwo[index].get_name() << endl;
	}

	cout << "========================\n\n";
}

void Attack(Viking a_attackingViking, Viking a_attackingTeam[], Viking a_targetTeam[]) {

	int lastAlive = 0;
	for (size_t i = 0; i < TEAM_SIZE; i++)								// loops through the targetted team's team members, checking for alive vikings
	{
		if (!a_targetTeam[i].isSlain) {
			lastAlive = i;												// if a living viking is found, the variable 'lastAlive' is set to their position
		}
	}

	if (lastAlive != 0) {												// if the attacking viking is alive
		Viking &a_target = a_targetTeam[rand() % lastAlive + 1];		// randomly selects a member of the targetted team

		a_attackingViking.attack(a_target);								// triggers the attacking viking's 'attack' function
	}
	else {
		a_attackingViking.attack(a_targetTeam[0]);
	}
}

void SelectAttacker(Viking a_attackingTeam[], Viking a_targetTeam[]) {

	BubbleSort(a_targetTeam);											//sort the team of targets

	bool vikingFound = false;
	while (!vikingFound) {
		Viking attackingViking = a_attackingTeam[rand() % TEAM_SIZE];		//randomly select a viking from the attacking team

		if (!attackingViking.isSlain) {
			Attack(attackingViking, a_attackingTeam, a_targetTeam);				//selected viking from attacking team attacks enemy team
			vikingFound = true;
		}
		else {
			vikingFound = false;
		}
	}
}

void ClearBuffer() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

bool CheckWin(Viking teamOne[], Viking teamTwo[]) {

	bool teamOneDead = true;
	bool teamTwoDead = true;

	for (size_t i = 0; i < TEAM_SIZE; i++)								//loops through all members of both teams
	{
		if (!teamOne[i].isSlain) {
			teamOneDead = false;										//if any member of a team is alive, the team is not considered wiped out
		}

		if (!teamTwo[i].isSlain) {
			teamTwoDead = false;										//if any member of a team is alive, the team is not considered wiped out
		}
	}

	if (teamOneDead) {													//if all members of a team are dead, the game is over and the opposite team wins
		std::cout << "It was tough, but Team Two wins! Congratulations.\n";
		return true;
	}
	else if (teamTwoDead) {												//if all members of a team are dead, the game is over and the opposite team wins
		std::cout << "It was tough, but Team One wins! Congratulations.\n";
		return true;
	}
}

void Swap(Viking *xp, Viking *yp) {										//function for swapping vikings in array, used for bubble sort
	Viking temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void BubbleSort(Viking a_teamToSort[]) {								//sorting function for viking health

	for (size_t i = 0; i < TEAM_SIZE - 1; i++)							//loops an amount of times equal to the team size
	{
		for (size_t x = 0; x < TEAM_SIZE - i - 1; x++)					//loops through all members of a team
		{
			if (a_teamToSort[x].get_health() < a_teamToSort[x + 1].get_health()) {	//if the viking's health is less than that of the next viking in the array
				Swap(&a_teamToSort[x], &a_teamToSort[x + 1]);						//swap vikings
			}
		}
	}
}