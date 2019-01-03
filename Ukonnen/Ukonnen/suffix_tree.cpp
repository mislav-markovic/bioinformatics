#include "suffix_tree.h"

const char NON_ACTIVE_EDGE = '\0x';

suffix_tree::suffix_tree() : root_{}, text_{}, prev_node_{ nullptr }, remainder_{ 0 }, active_point_{root_}
{
}

void suffix_tree::add(char symbol)
{
	//add symbol that is being processed to the end of text (updating all leaf nodes in process)
	text_ += symbol;


}

active_point_t::active_point_t(node& active_node) : active_node_{ active_node }, active_edge_{ NON_ACTIVE_EDGE }, active_length_{ 0 }
{
}