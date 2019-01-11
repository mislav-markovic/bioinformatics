#include <iostream>
#include <fstream>
#include <string>
#include "suffix_tree.h"

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

	suffix_tree *st = new suffix_tree(text);
	std::cout << st->build();
	return 0;
}

