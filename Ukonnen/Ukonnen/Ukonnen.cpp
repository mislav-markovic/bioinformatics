#include <iostream>
#include <fstream>
#include <string>
#include "suffix_tree.h"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << "Please write the filepath in the command line argument";
    return 0;
  }
  std::string text;
  std::string line;
  std::ifstream my_file;
  my_file.open(argv[1]);
  if (my_file.is_open())
  {
    while (getline(my_file, line))
    {
      text += line;
    }
    my_file.close();
  }
  else
  {
	  std::cout << "Unable to open file " << argv[1];
	  return 1;
  }

  text.push_back(suffix_tree::final_char);
  suffix_tree st{text};
  if (st.build() == true)
  {
    std::cout << "Tree made";
  }
  else
  {
    std::cout << "Tree not made";
  }
  return 0;
}
