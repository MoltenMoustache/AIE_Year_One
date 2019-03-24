#include <iostream>
#include <fstream>

using namespace std;

const int BUFFER_SIZE = 12;

int main() {
	char characterArray[BUFFER_SIZE] = { 'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e', '!'};

	char *character;

	ofstream fout("Data.dat", ios_base::out | ios::binary);
	fout.seekp(0, ios::beg);
	fout.write(characterArray, BUFFER_SIZE);

	fout.close();

	cout << "==\tFile Written!\t==" << endl << endl;



	ifstream fin("Data.dat", ios_base::in || ios::binary || ios::ate);

	streampos size = fin.tellg();
	character = new char[size];
	fin.seekg(0, ios::beg);
	//fin.seekg(5, ios::cur);
	fin.read(character, BUFFER_SIZE);
	cout << character;

	cout << endl;

	fin.close();

	system("pause");
}