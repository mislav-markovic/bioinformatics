#ifndef NODE_H
#define NODE_H
#include <vector>

namespace ukonnen
{
	class node
	{
		unsigned int from_;
		unsigned int to_;
		std::vector<node> children_;
	};
}
#endif //NODE_H