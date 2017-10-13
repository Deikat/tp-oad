#include <iostream>

#include "graph.hpp"


int main()
{
	Graph g;

	g.from_file("graph.in.txt");

	std::cout << g << std::endl;

	return 0;
}
