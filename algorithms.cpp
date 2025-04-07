#include "algorithms.hpp"
#include <limits>
using namespace std;
list<int> algorithms::bfs(list<vertex> &vertices) {
	int s = 0;
	list<int> res;
	list<int> queue;
	list<bool> colored = *new list<bool>(vertices.size);
	for (int i = 0; i < vertices.size; i++) {
		colored.set(i, false);
	}
	colored.set(s, true);
	queue.set(0, s);
	
	while(!queue.empty()) {
		int current = queue.pop();
		list<int> neighbors = vertices.get(current).neighbors;
		res.push(current);
		for (int i = 0; i < neighbors.size; i++) {
			int x = neighbors.get(i);
			if(!colored.get(x)) {
				colored.set(x, true);
				queue.push(x);
			}
		}
	}
	return res;
}
void algorithms::dfsRec(list<vertex> &vertices, list<bool> &colored, int s, list<int> &res) {
	colored.set(s, true);
	res.push(s);
	for(int i = 0; i < vertices.size; i++) {
		if (!colored.get(i))
			dfsRec(vertices, colored, i, res);
	}
}
list<int> algorithms::dfs(list<vertex> &vertices) {
	list<bool> colored = *new list<bool>(vertices.size);
	for (int i = 0; i < vertices.size; i++) {
		colored.set(i, false);
	}
	list<int> res;
	dfsRec(vertices, colored, 0, res);
	return res;
}
list<int> algorithms::dijkstra(Graph &g, int src) {
	int max_vertices = g.getVertices().size;
	list<int> distances(max_vertices);
	list<bool> colored(max_vertices);

	for (int i = 0; i < max_vertices; i++) {
		distances.set(i, numeric_limits<int>::max());
		colored.set(i, false);
	}
	distances.set(src, 0);

	for (int i = 0; i < max_vertices-1; i++) {
		int min = numeric_limits<int>::max();
		int index = -1;

		for (int j = 0; j <max_vertices; j++){
			if (!colored.get(j) && distances.get(j) <= min) {
				min = distances.get(j);
				index = j;
			}
		}
		int u = index;
		if (u == -1) break;

		colored.set(u, true);

		vertex current = g.getVertices().get(u);
		for (int i = 0; i < current.neighbors.size; i++) {
			int neighbor = current.neighbors.get(i);
			int weight = numeric_limits<int>::max();
			for (int j = 0; j < g.getEdges().size; j++) {
				edge e = g.getEdges().get(j);
				if ((e.src == u && e.dest == neighbor) || (e.src == neighbor && e.dest == u)) {
					weight = e.weight;
					break;
				}
			}

			if (!colored.get(neighbor) && distances.get(u) != numeric_limits<int>::max() &&
				distances.get(u) + weight < distances.get(neighbor)) {
				distances.set(neighbor, distances.get(u) + weight);
			}
		}
	}

	return distances;
}
list<edge> algorithms::prim(Graph &g) {
	int max_vertices = g.getVertices().size;
	list<edge> mst_edges;
	bool* in_mst = new bool[max_vertices];
	int* min = new int[max_vertices];
	int* parent = new int[max_vertices];
	for (int i = 0; i < max_vertices; i++) {
		in_mst[i] = false;
		min[i] = numeric_limits<int>::max();
		parent[i] = -1;
	}
	min[0] = 0;
	for (int i = 0; i < max_vertices - 1; i++) {
		int u = -1;
		int mval = numeric_limits<int>::max();
		for (int j = 0; j < max_vertices; j++) {
			if (!in_mst[j] && min[j] < mval) {
				mval = min[j];
				u = j;
			}
		}
		in_mst[u] = true;
		list<int> neighbors = g.getVertices().get(u).neighbors;
		for (int j = 0; j < neighbors.size; j++) {
			int v = neighbors.get(j);
			for(int k = 0; k < g.getEdges().size; k++) {
				edge e = g.getEdges().get(j);
				if ((e.src == u && e.dest == v) || (e.src == v && e.dest == u)) {
					if (!in_mst[v] && e.weight < min[v]) {
						min[v] = e.weight;
						parent[v] = u;
					}
				}
			}
		}
	}
	for (int i = 0; i < max_vertices; i++) {
		edge mst_edge;
		mst_edge.src = parent[v];
		mst_edge.dest = v;

		for (int j = 0; j < g.getEdges().size; j++) {
			edge e = g.getEdges().get(j);
			if ((e.src == mst_edge.src && e.dest == mst_edge.dest) ||
				(e.src == mst_edge.dest && e.dest == mst_edge.src)) {
				mst_edge.weight = e.weight;
				break;
			}
		}
		mst_edges.push(mst_edge);
	}
	delete[] in_mst;
	delete[] min;
	delete[] parent;

	return mst_edges;
}
