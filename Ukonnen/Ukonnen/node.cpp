#include "node.h"

node::node(const unsigned int from, const unsigned int to, const bool is_leaf, const bool is_root, suffix_link_t suffix_link,
           std::shared_ptr<index_t> text_end) : from_{from}, to_{to}, text_end_{std::move(text_end)}, is_leaf{is_leaf}, is_root{is_root},
  suffix_link{std::move(suffix_link)}
{
}

node::node(const unsigned int from, const unsigned int to, const bool is_leaf, suffix_link_t suffix_link,
           std::shared_ptr<index_t> text_end) : node(from, to, is_leaf, false, std::move(suffix_link), std::move(text_end))
{
}

node::node(std::shared_ptr<index_t> text_end) : node(0, 0, false, true, std::shared_ptr<node>(), std::move(text_end))
{
}

index_t node::edge_length() const noexcept
{
  return is_leaf ? *text_end_ - from_ : to_ - from_;
}

void node::split_off(const index_t at, char symbol_at)
{
  child_link_t second_half_edge = std::make_shared<node>(from_ + at, to_, true, suffix_link, text_end_);
  to_ = from_ + at;
  is_leaf = false;
  children.emplace(std::make_pair(symbol_at, std::move(second_half_edge)));
}
