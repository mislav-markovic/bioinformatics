#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string line;
	std::cout << "Hello World";
	std::ifstream myfile;
	myfile.open("example.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::cout << '\n' << line << '\n';
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
	return 0;
}

