#include "algorithms.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;
list<int> algorithms::bfs(list<vertex> &vertices) {
	int s = 0;
	list<int> res;
	list<int> queue;
	list<bool> visited = *new list<bool>(vertices.size);
	for (int i = 0; i < vertices.size; i++) {
		visited.set(i, false);
	}
	visited.set(s, true);
	queue.set(0, s);
	
	while(!queue.empty()) {
		int current = queue.pop();
		list<int> neighbors = vertices.get(current).neighbors;
		res.push(current);
		for (int i = 0; i < neighbors.size; i++) {
			int x = neighbors.get(i);
			if(!visited.get(x)) {
				visited.set(x, true);
				queue.push(x);
			}
		}
	}
	return res;
}
void algorithms::dfsRec(list<vertex> &vertices, list<bool> &visited, int s, list<int> &res) {
	visited.set(s, true);
	res.push(s);
	for(int i = 0; i < vertices.size; i++) {
		if (!visited.get(i))
			dfsRec(vertices, visited, i, res);
	}
}
list<int> algorithms::dfs(list<vertex> &vertices) {
	list<bool> visited = *new list<bool>(vertices.size);
	for (int i = 0; i < vertices.size; i++) {
		visited.set(i, false);
	}
	list<int> res;
	dfsRec(vertices, visited, 0, res);
	return res;
}
void algorithms::dijkstra(Graph &g, int src) {
	int max_vertices = g.getVertices().size;
	list<int> distances(max_vertices);
	list<bool> visited(max_vertices);

	for (int i = 0; i < max_vertices; i++) {
		distances.set(i, numeric_limits<int>::max());
		visited.set(i, false);
	}
	distances.set(src, 0);

	for (int i = 0; i < max_vertices-1; i++) {
		int min = numeric_limits<int>::max();
		int index = -1;

		for (int j = 0; j <max_vertices; j++){
			if (!visited.get(j) && distances.get(j) <= min) {
				min = distances.get(j);
				index = j;
			}
		}
		int u = index;
		if (u == -1) break;

		visited.set(u, true);

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

			if (!visited.get(neighbor) && distances.get(u) != numeric_limits<int>::max() &&
				distances.get(u) + weight < distances.get(neighbor)) {
				distances.set(neighbor, distances.get(u) + weight);
			}
		}
	}

	for (int i = 0; i < max_vertices; i++) {
		std::cout << "Vertex " << i << " distance: " << distances.get(i) << "\n";
	}
}
