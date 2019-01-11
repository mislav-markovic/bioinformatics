#include <iostream>
#include "suffix_tree.h"

int main()
{
  std::cout << "Hello World" << '\n';
  std::string s{"ABCA$"};
  suffix_tree tree{s};
  tree.build();
  std::string s1{ "ABC" };
  std::string s2{ "BC" };
  std::string s3{ "C" };
  std::string s4{ "AB" };
  std::string s5{ "A" };
  std::string s6{ "B" };

  std::cout << "Contains ABC: " << tree.contains(s1) << '\n';
  std::cout << "Contains BC: " << tree.contains(s2) << '\n';
  std::cout << "Contains C: " << tree.contains(s3) << '\n';
  std::cout << "Contains AB: " << tree.contains(s4) << '\n';
  std::cout << "Contains A: " << tree.contains(s5) << '\n';
  std::cout << "Contains B: " << tree.contains(s6) << '\n';
}
