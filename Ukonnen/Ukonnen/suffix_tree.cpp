#include "suffix_tree.h"
#include <iostream>
#include <utility>
const char non_active_edge = '\0';

suffix_tree::suffix_tree(std::string text) : current_end_{std::make_shared<index_t>(0)},
                                             root_{std::make_shared<node>(current_end_)}, text_{std::move(text)},
                                             remainder_{0}, active_point_{root_}
{
  root_->suffix_link = root_;
  text_.push_back(final_char);
}

bool suffix_tree::build()
{
  const index_t text_size = text_.size();
  for (; *current_end_ < text_size; ++*current_end_)
  {
    insert(text_[*current_end_]);
  }
  return remainder_ == 0;
}

//tree print method

void suffix_tree::print_to_console() const noexcept
{
  child_link_t observed_node{root_};
  std::cout << char(196);
  std::cout << "ROOT NODE";
  std::cout << char(196);
  std::cout << char(233) << std::endl;

  print_edges(root_, 11);
}

void finish_node(int len)
{
  std::cout << char(196);
  std::cout << char(196);
  std::cout << std::endl;
}

void suffix_tree::tab(int number_of_tabs) noexcept
{
  for (int i = 0; i < number_of_tabs; ++i)
    std::cout << " ";
  std::cout << char(192); // little L
  std::cout << char(196);
}

void suffix_tree::print_edges(child_link_t node, int number_of_tabs) const noexcept
{
  std::unordered_map<char, child_link_t> edges{node->children};
  std::unordered_map<char, child_link_t>::iterator it;

  for (it = edges.begin(); it != edges.end(); ++it)
  {
    tab(number_of_tabs);
    std::cout << edge(edges.at(it->first));
    std::cout << char(196);
    std::cout << char(233);

    if (node->children.at(it->first)->is_leaf)
    {
      std::cout << std::endl;
      //std::cout << char(196);
    }
    else
    {
      std::cout
        << std::endl;
      //visit the child node
      //std::cout << static_cast<int> (size);

      print_edges(node->children.at(it->first), number_of_tabs + 3 + edge(edges.at(it->first)).length());
    }
  }
}

//pretpostavka radi TESTIRAJ
bool suffix_tree::contains(std::string const& requested_suffix) const noexcept
{
  std::string suffix{requested_suffix};
  suffix.push_back(final_char);
  const index_t suffix_length{suffix.length()};
  index_t index{0};
  child_link_t observed_node{root_};
  while (index < suffix_length)
  {
    //see if the observed node had an edge that starts with the indexed character
    if (observed_node->children.count(suffix[index]) != 0)
    {
      //find the edge that starts with the index
      observed_node = observed_node->children.at(suffix[index]);
      //compare edge to matching suffix part
      std::string string_temp{suffix.substr(index, observed_node->edge_length())};
      //if the substring does not match the edge string value
      if (string_temp != edge(observed_node))
      {
        //it does not contain
        return false;
      }
      //if it does match, see if that is the leaf
      if (observed_node->is_leaf)
      {
        //if it is the leaf and we checked the entire string
        if (index + string_temp.length() == suffix_length)
        {
          //we found a substring
          return true;
        }
        //we didn't and we overshot the suffix length
        return false;
      }
      //if this is not the leaf, continue the search
      index += observed_node->edge_length();
    }
    else
    {
      break;
    }
  }
  return false;
}

std::string suffix_tree::edge(child_link_t const& node) const noexcept
{
  //input is a node, output is value of string on the edge
  return text_.substr(node->from_, node->edge_length());
}

child_link_t add_suffix_link(child_link_t const& prev_node, child_link_t node)
{
  if (prev_node)
  {
    if (!node->is_leaf) prev_node->suffix_link = node;
  }
  return node;
}

bool suffix_tree::insert(char symbol)
{
  remainder_++;
  child_link_t prev_node;
  while (remainder_ > 0)
  {
    if (active_point_.active_length == 0) active_point_.active_edge = symbol;
    //symbol is not found in tree
    if (active_point_.active_node->children.count(active_point_.active_edge) == 0)
    {
      child_link_t leaf = std::make_shared<node>(*current_end_, *current_end_, true, root_, current_end_);
      //if we constructed node in this step already, add suffix link and change prev_node to last node

      //add leaf as child (edge) to the active node
      active_point_.active_node->children.emplace(std::make_pair(symbol, std::move(leaf)));

      prev_node = add_suffix_link(prev_node, active_point_.active_node); // rule 2
    }
    else
    {
      child_link_t& child = active_point_.active_node->children.at(active_point_.active_edge);
      //if active length is larger then edge length we need to correct active point and run iteration again
      if (position_active_point(child)) continue;
      //symbol is already contained in tree
      //we only update active point and try to insert it when suffix grows (i.e. when this method is called next time)

      if (text_[child->from_ + active_point_.active_length] == symbol)
      {
        active_point_.active_length++;
        //smarter people decided that this was important edge case

        prev_node = add_suffix_link(prev_node, active_point_.active_node);

        //inserting failed in this step, try again with added symbol
        return false;
      }
      //symbol is not in the tree, we need to split edge (creating new internal node in process) and add new leaf node
      //split edge, first_half becomes internal node and gains the remaining part of edge as child node
      //i.e. if we split edge abcabcd with active length after first b (2), first node becomes ab, and second becomes cabcd
      child_link_t first_half = child->split_off(active_point_.active_length);
      //reset first half's suffix link, second half inherits nodes suffix link.
      first_half->suffix_link = root_;
      child_link_t leaf = std::make_shared<node>(*current_end_, *current_end_, true, root_, current_end_);
      //add leaf as child to new internal node
      first_half->children.emplace(std::make_pair(symbol, std::move(leaf)));
      //add second half as child to first half
      first_half->children.emplace(std::make_pair(text_[child->from_], child));
      //add first half as new child of active node
      active_point_.active_node->children[active_point_.active_edge] = first_half;
      //add suffix link if necessary
      prev_node = add_suffix_link(prev_node, first_half);
    }
    //if we got here we inserted something
    remainder_--;
    if (active_point_.active_node->is_root && active_point_.active_length > 0)
    {
      active_point_.active_length--;
      active_point_.active_edge = text_[*current_end_ - remainder_ + 1];
    }
    else
    {
      active_point_.active_node = active_point_.active_node->suffix_link;
    }
  }
  return true;
}

bool suffix_tree::position_active_point(child_link_t const& node) noexcept
{
  if (active_point_.active_length >= node->edge_length())
  {
    active_point_.active_length -= node->edge_length();
    active_point_.active_node = node;
    active_point_.active_edge = text_[node->from_ + active_point_.active_node->edge_length()];
    return true;
  }
  return false;
}

active_point_t::active_point_t(child_link_t active_node) : active_node{std::move(active_node)},
                                                           active_edge{non_active_edge}, active_length{0}
{
}
