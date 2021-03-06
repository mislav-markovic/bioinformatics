#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "suffix_tree.h"

std::string read_file(std::string& path)
{
  std::string line;
  std::string text;
  std::ifstream my_file;
  my_file.open(path);

  const auto start = std::chrono::high_resolution_clock::now();
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
    std::cout << "Unable to open file " << path << '\n';
  }

  const auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = end - start;

  std::cout << "Read " << text.length() << " characters in " << duration.count() / 1000 << " seconds" << '\n';

  return text;
}

std::string read_file(const char * text)
{
  std::string temp{ text };
  return read_file(temp);
}

double time(std::string path)
{
  int repeat_time = 30;
  std::string input{ read_file(path) };

  const auto start = std::chrono::high_resolution_clock::now();
  for(auto i = 0; i < repeat_time; ++i)
  {
    std::string temp{ input };
    {
      suffix_tree t{ temp };
      t.build();
    }
  }
  const auto end = std::chrono::high_resolution_clock::now();
  const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  return duration / repeat_time;
}


int main(int argc, char* argv[])
{
  //std::cout << "TREE OUTPUT TEST" << std::endl << std::endl;

  //std::string input_string{ "AAAAABAAA" };
  //suffix_tree tree{ input_string }; 
  //tree.build();
  //tree.print_to_console();

  if (argc < 2)
  {
    std::cout << "Please write the filepath in the command line argument" << '\n';
    return 1;
  }

  std::string file_path{argv[1]};

  const auto text{read_file(file_path)};

  suffix_tree st{text};

  std::cout << "Building Tree..." << '\n';
  const auto start = std::chrono::high_resolution_clock::now();
  if (st.build() == true)
  {
    std::cout << "Tree made" << '\n';
  }
  else
  {
    std::cout << "Tree not made" << '\n';
  }
  const auto end = std::chrono::high_resolution_clock::now();

  const auto duration = end - start;
  std::cout << "Time to build suffix tree: " << duration.count() / 1e9 << " seconds" << '\n';
  std::cout << std::endl;
  std::cout << "Would you like to display the tree?(displaying trees larger than 20 characters is not recommended)\n [y]es / [n]o\n";
  std::string inpStr;
  std::cin >> inpStr;
  std::cout << std::endl;
  if (inpStr == "y") {
	  st.print_to_console();
  }
  return 0;
}
