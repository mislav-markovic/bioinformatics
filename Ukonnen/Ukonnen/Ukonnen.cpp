#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "suffix_tree.h"

int main(int argc, char* argv[])
{
	std::cout << "TREE OUTPUT TEST" << std::endl << std::endl;

	std::string input_string{ "AAAAABAAA" };
	suffix_tree tree{ input_string }; 
	tree.build();
	tree.print_to_console();


	return 0;
  if (argc < 2)
  {
    std::cout << "Please write the filepath in the command line argument" << '\n';
    return 1;
  }
  else
  {
	  std::cout << "Reading from: " << argv[1] << '\n';
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
	  std::cout << "Unable to open file " << argv[1] << '\n';
	  return 1;
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = end - start;

  std::cout << "Read " << text.length() << " characters in " << duration.count() / 1000 << " seconds" << '\n';

  text.push_back(suffix_tree::final_char);
  suffix_tree st{text};

  std::cout << "Building Tree..." << '\n';
  start = std::chrono::high_resolution_clock::now();
  if (st.build() == true)
  {
    std::cout << "Tree made" << '\n';
  }
  else
  {
    std::cout << "Tree not made" << '\n';
  }
  end = std::chrono::high_resolution_clock::now();

  duration = end - start;
  std::cout << "Time to build suffix tree: " << duration.count() / 1000 << " seconds" << '\n';

  return 0;
}
