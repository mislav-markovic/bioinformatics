#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H
#include <string>
#include "node.h"


//active point data container as used here:
//https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english
struct active_point_t
{
  child_link_t active_node;
  //first symbol of a child node of active node.
  //just first symbol is enough since children are guaranteed to have unique starts of their suffixes.
  char active_edge;
  //how much of child's value is considered.
  unsigned int active_length;

  explicit active_point_t(child_link_t);
};

class suffix_tree
{
  //DO NOT CHANGE ORDER OF MEMBERS, unfortunately they are interdependent in their initialization

  //current progress in text
  std::shared_ptr<index_t> current_end_;
  //root of tree
  child_link_t root_;
  //text that is used to construct tree
  //add method should add to this string
  //maybe tree shouldn't own text??
  std::string text_;
  //how many suffixes need to be inserted into tree
  unsigned int remainder_;
  //active point is used in construction of tree
  active_point_t active_point_;

  //returns suffix value contained in node
  [[nodiscard]] std::string edge(child_link_t const&) const noexcept;
  //add symbol to suffix tree as a child of active node.
  //returns true if suffix is added, and false if it not.
  //suffix can't be added if it is found in tree, then remainder is increased and this method returns.
  //active point and remainder are managed by this method.
  bool insert(char symbol);
  //adjusts active point if active length is greater or equal to active edge length
  [[nodiscard]] bool position_active_point(child_link_t const&) noexcept;

  static void tab(int number_of_tabs) noexcept;
  void print_edges(child_link_t node, int number_of_tabs) const noexcept;

public:
  static const char final_char = '$';
  //default ctor, initializes pointers 
  explicit suffix_tree(std::string text);

  //builds suffix tree from text it was initialized.
  //manages current position, current end, calls insert method on every symbol of text.
  //return true if suffix tree was successfully completely built, and false if some suffixes remained for insertion   
  bool build();
  void print_to_console() const noexcept;
  //check if suffix is contained in tree
  [[nodiscard]] bool contains(std::string const& requested_suffix) const noexcept;
};
#endif //SUFFIX_TREE_H
