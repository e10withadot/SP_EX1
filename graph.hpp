// ey.gellis@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "data_strct.hpp"
using namespace data;
namespace graph {
	struct edge {
		int src;
		int dest;
		int weight;
	};
	struct vertex {
		list<int> neighbors;
	};
	class Graph {
		private:
			int max_vertices;
			list<edge> edges;
			list<vertex> vertices;
		public:
			Graph(int max_vertices) : max_vertices(max_vertices), edges(*new list<edge>(6)), vertices(*new list<vertex>(max_vertices)) {}; 
			list<vertex> getVertices();
			list<edge> getEdges();
			/*
			* Adds an edge to the graph.
			*/
			void addEdge(int src, int dest, int weight = 1);
			/*
			* Removes an edge from the graph.
			*/
			void removeEdge(int src, int dest);
			void print_graph();
	};
}
#endif
