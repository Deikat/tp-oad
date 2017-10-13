#include <iostream>
#include <fstream>

#include "graph.hpp"


Node::Node() : id(0)
{
}

Node::Node(int id) : id(id)
{
}

int Node::get_id() const
{
	return id;
}

void Node::add_in_edge(int id)
{
	in_edges.push_back(id);
}

void Node::add_out_edge(int id)
{
	out_edges.push_back(id);
}

Edge::Edge()
	: id(0), source_id(0), target_id(0), weight(0)
{
}

Edge::Edge(int id, int source_id, int target_id, Weight weight)
	: id(id), source_id(source_id), target_id(target_id), weight(weight)
{
}

int Edge::get_source_id() const
{
	return source_id;
}

int Edge::get_target_id() const
{
	return target_id;
}

Weight Edge::get_weight() const
{
	return weight;
}


Graph::Graph()
{
}

const std::vector<Node>& Graph::get_nodes() const
{
	return nodes;
}

const std::vector<Edge>& Graph::get_edges() const
{
	return edges;
}

void Graph::add_node(int id)
{
	nodes.push_back(Node(id));
}

void Graph::add_edge(int source_id, int target_id, Weight weight)
{
	int edge_id = edges.size();
	nodes[source_id].add_out_edge(target_id);
	nodes[target_id].add_in_edge(source_id);
	edges.push_back(Edge(edge_id, source_id, target_id, weight));
}

void Graph::from_file(const std::string& filename)
{
	std::ifstream graphfile(filename);
	if(!graphfile)
	{
		std::cout << "Error while opening the file " << filename << std::endl;
		return;
	}

	int i, id, target_id;
	Weight weight;
	int nodes_length;
	int edges_length;

	graphfile >> nodes_length;
	graphfile >> edges_length;
	nodes = std::vector<Node>(nodes_length);
	edges = std::vector<Edge>(edges_length);

	for (i = 0; i < nodes_length; i++)
	{
		add_node(i);
	}
	for (i = 0; i < edges_length; i++)
	{
		graphfile >> id;
		graphfile >> target_id;
		graphfile >> weight;
		add_edge(id, target_id, weight);
	}
}

void Graph::to_file(const std::string& filename)
{

}

std::ostream& operator<<(std::ostream& os, const Graph& g)
{
	os << g.get_nodes().size() << "\n" << g.get_edges().size() << "\n";
	for (const Node &node : g.get_nodes())
	{
		os << node.get_id() << "\n";
	}
	os << "\n";
	for (const Edge &edge : g.get_edges())
	{
		os << edge.get_source_id() << " "
			<< edge.get_target_id() << " "
			<< edge.get_weight() << "\n";
	}

	return os;
}
