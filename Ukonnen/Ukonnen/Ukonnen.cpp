#include <iostream>
#include "suffix_tree.h"

int main()
{
  std::cout << "Hello World";
  std::string s{"TEST"};
  suffix_tree tree{s};
  tree.build();
}
