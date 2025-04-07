#include "data_strct.hpp"
using namespace data;
namespace graph {
	struct edge {
		int src;
		int dest;
		int weight;
	};
	struct vertex {
		list<Integer> neighbors;
	};
	class graph {
		private:
			int max_vertices;
			list<edge> edges;
			list<vertex> vertices;
		public:
			graph(int max_vertices); 
			void addEdge(int src, int dest, int weight = 1);
			void removeEdge(int src, int dest);
			void print_graph();
	};
}
