// ey.gellis@gmail.com
#include "data_strct.hpp"
using namespace data;
#include "graph.hpp"
using namespace graph;
namespace algorithms {
	list<int> bfs(list<vertex> &vertices);
	void dfsRec(list<vertex> &vertices, list<bool> &visited, int s, list<int> &res);
	list<int> dfs(list<vertex> &vertices);
	list<int> dijkstra(Graph &g, int src);
	list<edge> prim(Graph &g);
	int findSet(int vertex, int* parent);
	void unionSets(int u, int v, int* parent, int* rank);
	list<edge> kruskal(Graph &g);
}
