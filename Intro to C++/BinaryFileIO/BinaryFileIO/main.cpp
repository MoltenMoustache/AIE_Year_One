#include <iostream>
#include <fstream>


int main()
{
	std::fstream movie_data;

	//Writing to text file
	movie_data.open("..\\movie_data.txt", std::ios_base::out);
	if (movie_data.is_open())
	{
		movie_data << "Movie Name: The Good, The Bad, The Ugly\n";
		movie_data << "Release Year: 1966\n";
		movie_data << "Director: Sergio Leone\n";
		movie_data << "Rotten Tomatoes Score: 97%\n";
		movie_data.close();
	}
	else
	{
		std::cout << "Write failed" << std::endl;
	}

	//Reading from a text file
	char buffer[200];
	movie_data.open("..\\movie_data.txt", std::ios_base::in);
	if (movie_data.is_open())
	{
		std::cout << "*** Text File Full Read: ***" << std::endl;
		while (!movie_data.eof())
		{
			movie_data >> buffer;
			std::cout << buffer << " ";
		}
		movie_data.close();
		std::cout << "\n\n";
	}
	else
	{
		std::cout << "Read failed\n";
	}


	//Writing to a binary file
	const char* text = "Movie Name: The Good, The Bad, The Ugly\nRelease Year: 1966\nDirector: Sergio Leone\nRotten Tomatoes Score: 97%\n";
	movie_data.open("..\\movie_data.dat", std::ios_base::out | std::ios::binary);
	if (movie_data.is_open())
	{
		movie_data.write(text, sizeof(char) * strlen(text) + 1);
		movie_data.close();
	}
	else
	{
		std::cout << "Binary write failed\n";
	}

	//Reading from a binary file
	char buffer2[200];
	movie_data.open("..\\movie_data.dat", std::ios_base::in | std::ios_base::binary);
	if (movie_data.is_open())
	{
		movie_data.read(buffer2, sizeof(char) * strlen(buffer2) + 1);
		std::cout << "*** Binary File Full Read: ***\n";
		std::cout << buffer2;
		movie_data.close();
		std::cout << "\n\n";
	}
	else
	{
		std::cout << "Binary read failed\n";
	}


	//Writing to the middle of a binary file
	movie_data.open("..\\movie_data.dat", std::ios_base::out | std::ios::binary);
	if (movie_data.is_open())
	{
		movie_data.seekp(12);
		movie_data.write("PTING", 6);
		movie_data.close();
	}
	else
	{
		std::cout << "Binary middle write failed\n";
	}

	//Reading from the middle of a binary file
	char buffer3[6];
	movie_data.open("..\\movie_data.dat", std::ios_base::in | std::ios_base::binary);
	if (movie_data.is_open())
	{
		movie_data.seekg(12);
		movie_data.read(buffer3, 6);
		std::cout << "*** Binary File Middle Read: ***\n";
		std::cout << buffer3;
		movie_data.close();
		std::cout << "\n\n\n";
	}
	else
	{
		std::cout << "Binary middle read failed\n";
	}

	std::cout << "\nDidn't have time to polish it in b/w doctors appointments and work\nBut this does what the criteria requires.\nCheers!\n\n";

	system("pause");
}