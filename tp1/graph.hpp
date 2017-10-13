#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>

class Node
{
	int id;
	std::vector<int> in_edges;
	std::vector<int> out_edges;
public:
	Node();
	Node(int id);
	int get_id() const;
	void add_in_edge(int id);
	void add_out_edge(int id);
};

typedef int Weight;

class Edge
{
	int id;
	int source_id;
	int target_id;
	Weight weight;
public:
	Edge();
	Edge(int id, int source_id, int target_id, Weight weight);
	int get_source_id() const;
	int get_target_id() const;
	Weight get_weight() const;
};

class Graph
{
	std::vector<Node> nodes;
	std::vector<Edge> edges;
public:
	Graph();
	const std::vector<Node>& get_nodes() const;
	const std::vector<Edge>& get_edges() const;
	void add_node(int id);
	void add_edge(int id, int target_id, Weight weight);
	void from_file(const std::string& filename);
	void to_file(const std::string& filename);
	std::string to_string();
};

#endif
