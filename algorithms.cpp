#include "graph.hpp"
using namespace graph;
#include "data_strct.hpp"
using namespace data;
namespace algorithms {
	list<int> bfs(list<vertex> &vertices) {
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
	void dfsRec(list<vertex> &vertices, list<bool> &visited, int s, list<int> &res) {
		visited.set(s, true);
		res.push(s);
		for(int i = 0; i < vertices.size; i++) {
			if (!visited.get(i))
				dfsRec(vertices, visited, i, res);
		}
	}
	list<int> dfs(list<vertex> &vertices) {
		list<bool> visited = *new list<bool>(vertices.size);
		for (int i = 0; i < vertices.size; i++) {
			visited.set(i, false);
		}
		list<int> res;
		dfsRec(vertices, visited, 0, res);
		return res;
	}
}
