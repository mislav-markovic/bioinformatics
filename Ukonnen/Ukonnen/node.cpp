#include "node.h"

namespace ukonnen {
	using ukonnen::node;


	node::node(unsigned int from, unsigned int to, bool is_leaf, bool is_root, suffix_tree const & tree) : from_{from}, to_{to}, is_leaf_{is_leaf}, is_root_{is_root}, tree_{tree}, suffix_link_{nullptr}, children_{}
	{
	}

	node::node(unsigned int from, unsigned int to, bool is_leaf, suffix_tree const& tree) : node(from, to, is_leaf, false, tree) {}

	node::node(suffix_tree const& tree) : node(0, 0, false, true, tree)
	{
	}

}