#include "node.h"


node::node(unsigned int from, unsigned int to, bool is_leaf, bool is_root) : from_{ from }, to_{ to }, is_leaf_{ is_leaf }, is_root_{ is_root }, suffix_link_{ nullptr }, children_{}
{
}

node::node(unsigned int from, unsigned int to, bool is_leaf) : node(from, to, is_leaf, false) {}

node::node() : node(0, 0, false, true)
{
}