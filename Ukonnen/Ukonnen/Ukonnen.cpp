#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "suffix_tree.h"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << "Please write the filepath in the command line argument";
    return 1;
  }
  std::string text;
  std::string line;
  std::ifstream my_file;
  my_file.open(argv[1]);

  auto start = std::chrono::high_resolution_clock::now();
  if (my_file.is_open())
  {
    while (std::getline(my_file, line))
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

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = end - start;
  std::cout << "Time to read file: " << duration.count() << " seconds" << '\n';

  start = std::chrono::high_resolution_clock::now();
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
  end = std::chrono::high_resolution_clock::now();

  duration = end - start;
  std::cout << "Time to build suffix tree: " << duration.count() << " seconds" << '\n';
  return 0;
}
