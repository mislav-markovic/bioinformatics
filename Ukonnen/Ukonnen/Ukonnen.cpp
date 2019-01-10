#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
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

	for (int i = 0; i < argc; ++i)
		std::cout << "\n" << i << argv[i] << "\n";

	return 0;
}

