#include "pch.h"
#include <iostream>
#include "reader_writer.h"

int main()
{
  std::cout << "Hello World!\n";
  std::filesystem::path i{"in.txt"};
  std::filesystem::path o{ "out.txt" };

  reader_writer rw{i, o};
}

