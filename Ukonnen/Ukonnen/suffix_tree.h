#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H
#include <string>
#include "node.h"

//active point data container as used here:
//https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english
struct active_point_t {
	//non-owning raw pointer, do not free
	node& active_node_;
	//first symbol of a child node of active node.
	//just first symbol is enough since children are guaranteed to have unique starts of their suffixes.
	char active_edge_;
	//how much of child's value is considered.
	unsigned int active_length_;

	active_point_t(node&);
};

class suffix_tree
{
	//DO NOT CHANGE ORDER OF MEMBERS, unfortunately they are interdependent in their initialization
	//root of tree
	node root_;
	//text that is used to construct tree
	//add method should add to this string
	//maybe tree shouldn't own text??
	std::string const& text_;
	//node constructed in previous step (needed in some steps of algorithm)
	//non-owning raw pointer, do not free
	node* prev_node_;
	//how many suffixes need to be inserted into tree
	unsigned int remainder_;
	//active point is used in construction of tree
	active_point_t active_point_;
	//current position in text
	unsigned int position_;
	//returns suffix value contained in node
	[[nodiscard]] std::string_view node_value(node const&) const noexcept;
	//returns child node whose value starts with given symbol
	[[nodiscard]] node const& get_child(node const& parent, char symbol) const noexcept;
	void update_active_point_after_insert(char);

public:
	//default ctor, initializes pointers 
	suffix_tree(std::string const& text);
	//add symbol to suffix tree
	void add(char symbol);
	//builds suffix tree from text it was initialized.
	void build();
	//check if suffix is contained in tree
	[[nodiscard]] bool contains(std::string const& suffix) const noexcept;
	//returns view into entire text constructed so far.
	[[nodiscard]] std::string_view text() const noexcept;
};
#endif //SUFFIX_TREE_H