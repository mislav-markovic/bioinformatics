#ifndef NODE_H
#define NODE_H
#include <unordered_map> 
#include <memory>

class node;
class suffix_tree;

typedef std::shared_ptr<node> child_link_t;
typedef std::shared_ptr<node> suffix_link_t;
typedef std::size_t index_t;

//value is [from_, to_) for non-leaf (internal) nodes.
//leaf nodes have [from_, *text_end_) value.
//root node has no value.
//edges are calculated from nodes by suffix tree when needed.
class node
{
	//needed so that suffix tree can extract edge value between nodes
	friend suffix_tree;
	//start of part of suffix defined by this node.
	index_t from_;
	//end of suffix denoted by this node.
	index_t to_;
	//end index for leaf nodes.
	std::shared_ptr<index_t> text_end_;
	//ctor that other ctors delegate to.
	node(unsigned int from, unsigned int to, bool is_leaf, bool is_root, suffix_link_t suffix_link, std::shared_ptr<index_t> text_end);
public:
	//ctor for non-root node.
	node(unsigned int from, unsigned int to, bool is_leaf, suffix_link_t suffix_link, std::shared_ptr<index_t> text_end);
	//ctor for root node
  explicit node(std::shared_ptr<index_t> text_end);
	//leafs define suffixes that go from some point in text to the end of text.
	//as text grows to_ member of node does not need to be updated
	bool is_leaf;
	//root node is special case of internal node
	const bool is_root;
	//pointer to this nodes suffix link, by default points to root node
	suffix_link_t suffix_link;
	//child nodes
	std::unordered_map<char, child_link_t> children;

	//returns length of edge that connects this node to its parent
	[[nodiscard]] index_t edge_length() const noexcept;

	//modifies this node so that its value is now [from_, from_ + at), this node stops being leaf node.
	//creates new node whose value is [from_ + at, to_), new node becomes child of this node
	//e.g. node with {from_ : 3, to_ : 7}, after calling split_off(2) node is modified to be node {from_: 3, to_: 5}
	//and new node is created node {from_: 5, to_: 7}
	void split_off(index_t at, char symbol_at);
};

#endif //NODE_H