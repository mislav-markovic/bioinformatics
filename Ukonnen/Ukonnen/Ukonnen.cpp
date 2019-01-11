#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{	
	if (argc < 2) {
		std::cout << "Please write the filepath in the command line argument";
		return 0;
	}

	std::string text;
	std::ifstream myfile;
	myfile.open(argv[1]);
	
	if (myfile.is_open())
	{
		while (getline(myfile, text))
		{
			std::cout << '\n' << text << '\n';
		}
		myfile.close();
	}
	else std::cout << "Unable to open file " << argv[1];

	return 0;
}

