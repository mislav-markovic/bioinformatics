#ifndef NODE_H
#define NODE_H
#include <vector>

class node
{
	//start of part of suffix defined by this node
	unsigned int from_;
	//end of suffix denoted by this node.
	unsigned int to_;
	//ctor that other ctors delegate to
	node(unsigned int from, unsigned int to, bool is_leaf, bool is_root);
public:
	//ctor for non-root node
	node(unsigned int from, unsigned int to, bool is_leaf);
	//ctor for root node
	node();
	//leafs define suffixes that go from some point in text to the end of text.
	//as text grows to_ member of node does not need to be updated
	const bool is_leaf_;
	//root node is significant when active node is determined after node splitting occurs
	const bool is_root_;
	//pointer to this nodes suffix link, nullptr if no link exists.
	node* suffix_link_;
	//child nodes
	std::vector<node> children_;
};
#endif //NODE_H