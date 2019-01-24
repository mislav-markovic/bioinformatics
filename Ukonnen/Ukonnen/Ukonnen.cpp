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

void measure()
{
  std::string folder{"C:/Git/bioinformatics/Ukonnen/Ukonnen/"};


  std::string file_100{"100_chars.txt"};
  std::cout << "Reading file: " << file_100 << ", Average time: " << time(folder + file_100) << '\n';

  std::string file_1k{"1k_chars.txt"};
  std::cout << "Reading file: " << file_100 << ", Average time: " << time(folder + file_100) << '\n';

  std::string file_10k{"10k_chars.txt"};
  std::cout << "Reading file: " << file_10k << ", Average time: " << time(folder + file_10k) << '\n';

  std::string file_100k{"100k_chars.txt"};
  std::cout << "Reading file: " << file_100k << ", Average time: " << time(folder + file_100k) << '\n';

  std::string file_1mil{"1mil_chars.txt"};
  std::cout << "Reading file: " << file_1mil << ", Average time: " << time(folder + file_1mil) << '\n';

  std::string file_10mil{"10mil_chars.txt"};
  std::cout << "Reading file: " << file_10mil << ", Average time: " << time(folder + file_10mil) << '\n';

  std::string file_ecoli{"ecoli.txt"};
  std::cout << "Reading file: " << file_ecoli << ", Average time: " << time(folder + file_ecoli) << '\n';

  std::string throwaway{};
  std::cin >> throwaway;
}

int main(int argc, char* argv[])
{
  //std::cout << "TREE OUTPUT TEST" << std::endl << std::endl;

  //std::string input_string{ "AAAAABAAA" };
  //suffix_tree tree{ input_string }; 
  //tree.build();
  //tree.print_to_console();

  //measure();
  //return 0;

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

  return 0;
}
