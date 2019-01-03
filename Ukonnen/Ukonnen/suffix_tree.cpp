#include "suffix_tree.h"

const char NON_ACTIVE_EDGE = '\0x';

suffix_tree::suffix_tree() : root_{}, text_{}, prev_node_{ nullptr }, remainder_{ 0 }, active_point_{}
{
}

active_point_t::active_point_t() : active_node_{ nullptr }, active_edge_{ NON_ACTIVE_EDGE }, active_length_{ 0 }
{
}