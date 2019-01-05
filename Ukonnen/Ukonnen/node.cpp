#include "node.h"


node::node(unsigned int from, unsigned int to, bool is_leaf, bool is_root, suffix_link_t suffix_link) : from_{ from }, to_{ to }, is_leaf_{ is_leaf }, is_root_{ is_root }, suffix_link_{ suffix_link }, children_{}
{ }

node::node(unsigned int from, unsigned int to, bool is_leaf, suffix_link_t suffix_link) : node(from, to, is_leaf, false, suffix_link) {}

node::node() : node(0, 0, false, true, std::weak_ptr<node>())
{
	suffix_link_ = weak_from_this();
}