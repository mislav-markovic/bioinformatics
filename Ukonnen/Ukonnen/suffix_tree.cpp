#include "suffix_tree.h"

const char NON_ACTIVE_EDGE = '\0x';
const char FINAL_CHAR = '$';


suffix_tree::suffix_tree(std::string const& text) : root_{ std::move(std::make_shared<node>()) },
text_{ text }, remainder_{ 0 }, active_point_{ root_ },
current_position_{ 0 },
current_end_{ std::move(std::make_shared<index_t>(0)) }
{ }

void suffix_tree::build() {
	for (index_t pos = 0; pos < text_.size; ++pos) {
		char value = text_[pos];
		(*current_end_)++;
		if (insert(value)) current_position_ = *current_end_;
	}
	if (remainder_ > 0) insert(FINAL_CHAR);
}

/*
void suffix_tree::build()
{
	//TODO: loop the code bellow

	//end condition
	//TODO: consider if remainder is >0
	if (++position_ > text_.size) {
		return;
	}

	//symbol that will be added to suffix tree
	char symbol = text_.at(position_);
	remainder_++;
	prev_node_ = nullptr;

	//if-else that takes care of updating the active point
	//if previous suffix was not found in tree
	if (active_point_.active_edge_ == NON_ACTIVE_EDGE) {
		//iterate trough children and check if they implicitly contain suffix
		for (node const& n : active_point_.active_node_.children_) {
			//if suffix is contained update active point to that edge
			if (node_value(n).front() == symbol) {
				active_point_.active_edge_ = symbol;
				active_point_.active_length_ = 1;
				break;
			}
		}
	}
	//check if current suffix is also contained in active edge
	else {
		std::string_view edge = node_value(get_child(active_point_.active_node_, active_point_.active_edge_));

		//we reached end of edge
		if (active_point_.active_length_ + 1 == edge.size) {
			//TODO
		}
		else {
			char value = edge.at(active_point_.active_length_ + 1);

			//symbol is still implicitly contained in tree
			if (value == symbol) {
				active_point_.active_length_++;
			}
			else {
				//split off and insert
				node n{ position_, position_ + 1, true };
				active_point_.active_node_.split_off(active_point_.active_length_);
				active_point_.active_node_.children_.push_back(n);
				remainder_--;

				//if another node was created during this step, link it to this node
				if (prev_node_ != nullptr) {
					prev_node_->suffix_link_ = &active_point_.active_node_;
				}

				//set this node as last created node
				prev_node_ = &active_point_.active_node_;

				//update active point
				active_point_.active_length_--;
				active_point_.active_edge_ = value;
			}
		}
	}

	//if-else that takes care of inserting the suffix if possible and changing the remainder variable
	//suffix is not contained in tree (simplest base case)
	if (active_point_.active_edge_ == NON_ACTIVE_EDGE) {
		node n{ position_, position_ + 1, true };
		//insert new node as child of active node
		active_point_.active_node_.children_.push_back(n);
		//one suffix added
		remainder_--;
	}
	//active point is the middle of edge
	else {
		//we can't insert in this step so we just increment remainder
		remainder_++;
	}
}
*/

active_point_t::active_point_t(child_link_t& active_node) : active_node_{ active_node }, active_edge_{ NON_ACTIVE_EDGE }, active_length_{ 0 }
{ }
