#include <iostream>
#include "suffix_tree.h"

int main()
{
  std::cout << "Hello World" << '\n';
  std::string s{"ABC"};
  suffix_tree tree{s};
  tree.build();
}
