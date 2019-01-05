#include "node.h"


node::node(unsigned int from, unsigned int to, bool is_leaf, bool is_root, suffix_link_t suffix_link, std::shared_ptr<index_t> text_end) :
	from_{ from }, to_{ to }, 
	is_leaf_{ is_leaf }, is_root_{ is_root }, 
	suffix_link_{ suffix_link }, children_{},
	text_end_{text_end}
{ }

node::node(unsigned int from, unsigned int to, bool is_leaf, suffix_link_t suffix_link, std::shared_ptr<index_t> text_end) : node(from, to, is_leaf, false, suffix_link, text_end) {}

node::node(std::shared_ptr<index_t> text_end) : node(0, 0, false, true, std::weak_ptr<node>(), text_end)
{
	suffix_link_ = weak_from_this();
}

index_t node::edge_length() const noexcept
{
	//TODO
	return index_t();
}
