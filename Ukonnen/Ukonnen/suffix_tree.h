#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H
#include <string>
#include "node.h"

namespace ukonnen
{
  class suffix_tree
  {
	  node root_;
  public:
    suffix_tree();
    ~suffix_tree();
    void add(char symbol);
    [[nodiscard]] bool contains(std::string const&) const noexcept;
  };
}
#endif //SUFFIX_TREE_H