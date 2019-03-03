/*=============================
	 J O S H		M O T E N
  =============================

	File: main.cpp
	Date Modified: 20/2/2019

	Modifications:
	- Added diagonal win condition.
  =============================*/

#include <iostream>

using namespace std;

//constant variable declarations
const int MAP_SIZE = 3;

const char* EMPTY_TILE = "[ \xb0 ]";
const char* CROSS_TILE = "[ X ]";
const char* KNOT_TILE = "[ O ]";

const int EMPTY = 0;
const int CROSS = 1;
const int KNOT = 2;
// the board
int GAME_MAP[MAP_SIZE][MAP_SIZE];

bool isPlayerOne = true;

//function declarations
void DrawMap();
void TakeInput();
bool CheckWinCondition(int turn);
void WinText();
void DrawText();

int main() {
	int turns = 0;
	bool isGameOver = false;

	while (!isGameOver) {
		DrawMap();
		CheckWinCondition(turns);

		if (CheckWinCondition(turns) == true) {
			if (turns != 9){
				WinText();
			}
			else {
				DrawText();
			}
			isGameOver = true;
		}
		else {
			isGameOver = false;
			TakeInput();
			isPlayerOne = !isPlayerOne;
			turns += 1;
		}

		
	}

	system("pause");
}

void DrawMap() {
	system("cls");
	cout << endl;

	cout << " T I C - T A C - T O E ! \n \n";

	for (int y = 0; y < MAP_SIZE; y++)
	{
		cout << "\t";
		for (int x = 0; x < MAP_SIZE; x++)
		{
			if (GAME_MAP[y][x] != CROSS && GAME_MAP[y][x] != KNOT) {
				GAME_MAP[y][x] = EMPTY;
			}

			switch (GAME_MAP[x][y]) {
			case EMPTY:
				cout << EMPTY_TILE;
				break;
			case CROSS:
				cout << CROSS_TILE;
				break;
			case KNOT:
				cout << KNOT_TILE;
				break;
			}
		}
		cout << endl;
	}
}

void TakeInput() {
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	int playerTile = CROSS;

	if (isPlayerOne) {
		playerTile = CROSS;
	}
	else {
		playerTile = KNOT;
	}

	if (isPlayerOne) {
		cout << endl << "Using the numpad, select a tile" << endl << "You are Crosses." << endl;
	}
	else {
		cout << endl << "Using the numpad, select a tile" << endl << "You are Knots." << endl;
	}

	

	int selectedTile;
	cin >> selectedTile;
	if (cin.fail()) {
		cout << "Not a number!\n";
		system("pause");
		TakeInput();
	}else if (selectedTile > 9 || selectedTile < 1) {
		cout << "Number outside of range!\n";
		system("pause");
		TakeInput();
	}

	//sort
	switch (selectedTile)
	{
	case 7:
		if (GAME_MAP[0][0] == EMPTY) {
			GAME_MAP[0][0] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	case 8:
		if (GAME_MAP[1][0] == EMPTY) {
			GAME_MAP[1][0] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	case 9:
		if (GAME_MAP[2][0] == EMPTY) {
			GAME_MAP[2][0] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	case 4:
		if (GAME_MAP[0][1] == EMPTY) {
			GAME_MAP[0][1] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	case 5:
		if (GAME_MAP[1][1] == EMPTY) {
			GAME_MAP[1][1] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	case 6:
		if (GAME_MAP[2][1] == EMPTY) {
			GAME_MAP[2][1] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	case 1:
		if (GAME_MAP[0][2] == EMPTY) {
			GAME_MAP[0][2] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	case 2:
		if (GAME_MAP[1][2] == EMPTY) {
			GAME_MAP[1][2] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	case 3:
		if (GAME_MAP[2][2] == EMPTY) {
			GAME_MAP[2][2] = playerTile;
		}
		else {
			cout << "Tile occupied.\n";
			system("pause");
			TakeInput();
		}
		break;
	default:
		break;
	}

}

bool CheckWinCondition(int turn) {

	//checking for horizontal/vertical matched tiles
	for (size_t y = 0; y < MAP_SIZE; y++) //iterates through rows one by one
	{
		for (size_t x = 0; x < MAP_SIZE; x++) //iterates through columns one by one
		{
			if (GAME_MAP[y][x] != EMPTY && GAME_MAP[y][x] == GAME_MAP[y][x + 1] && GAME_MAP[y][x + 2] == GAME_MAP[y][x]) {
				return true;
			}
			else if (GAME_MAP[y][x] != EMPTY && GAME_MAP[y][x] == GAME_MAP[y + 1][x] && GAME_MAP[y + 2][x] == GAME_MAP[y][x]) {
				return true;
			}
		}
	}

	//checking for diagonal matched tiles
	if (GAME_MAP[1][1] != EMPTY) {
		if (GAME_MAP[1][1] == GAME_MAP[0][0] && GAME_MAP[1][1] == GAME_MAP[2][2]) {
			return true;
		}
		else if (GAME_MAP[1][1] == GAME_MAP[0][2] && GAME_MAP[1][1] == GAME_MAP[2][0]) {
			return true;
		}
	}

	//checking for draw
	if (turn == 9) {
		return true;
	}
	else {
		return false;
	}
}

void WinText() {

	isPlayerOne = !isPlayerOne;

	if (isPlayerOne) {
		cout << "Congratulations crosses! You win!\n";
	}
	else {
		cout << "Congratulations knots! You win!\n";
	}

	
}

void DrawText() {
	cout << "Uh-oh! The game is a draw!\n";
}