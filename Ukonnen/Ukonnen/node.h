#ifndef NODE_H
#define NODE_H
#include <vector>
#include "suffix_tree.h"

namespace ukonnen
{
	class node
	{
		//start of part of suffix defined by this node
		unsigned int from_;
		//end of suffix denoted by this node.
		unsigned int to_;
		//leafs define suffixes that go from some point in text to the end of text.
		//as text grows to_ member of node does not need to be updated
		bool is_leaf_;
		//root node is significant when active node is determined after node splitting occurs
		bool is_root_;
		//pointer to this nodes suffix link, nullptr if no link exists.
		node* suffix_link_;
		//tree this node is part of, needed for O(1) updates to leaf nodes.
		suffix_tree const& tree_;
		//child nodes
		std::vector<node> children_;
	};
}
#endif //NODE_H