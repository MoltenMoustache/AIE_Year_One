#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char characterArray[] = { 'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e', '!'};

	char character;
	int integer;
	int charArraySize = sizeof(characterArray);

	ofstream fout("Data.dat", ios_base::out | ios::binary);

	for (size_t i = 0; i < charArraySize; i++)
	{
		fout.write(&characterArray[i], charArraySize);
	}

	fout.close();

	cout << "==\tFile Written!\t==" << endl << endl;



	ifstream fin("Data.dat", ios_base::in || ios::binary);

	fin.seekg(5, ios::cur);
	while (!fin.eof() && fin.peek() != EOF) {
		fin.read((char*)&character, charArraySize);
		cout << character;
	}

	cout << endl;

	fin.close();

	system("pause");
}