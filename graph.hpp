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
	class graph {
		private:
			int max_vertices;
			list<edge> edges;
			list<vertex> vertices;
		public:
			graph(int max_vertices) : max_vertices(max_vertices), edges(*new list<edge>(6)), vertices(*new list<vertex>(max_vertices)) {}; 
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
