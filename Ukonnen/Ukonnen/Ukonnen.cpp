#include <iostream>
#include <fstream>
#include <string>
#include "suffix_tree.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Please write the filepath in the command line argument";
		return 0;
	}

	std::string text;
	std::string line;
	std::ifstream myfile;
	myfile.open(argv[1]);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			text += line;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file " << argv[1];

	suffix_tree *st = new suffix_tree(line);
	if (st->build() == true)
	{
		std::cout << "Tree made";
	}
	else
	{
		std::cout << "Tree not made";
	}
	return 0;
}

