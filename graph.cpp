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
			graph(int max_vertices) {
				this->max_vertices = max_vertices;
				this->edges = *new list<edge>(6);
				this->vertices = *new list<vertex>(this->max_vertices);
			}
			/*
			* Adds an edge to the graph.
			*/
			void addEdge(int src, int dest, int weight = 1) {
				edge e = *new edge();
				e.src = src;
				e.dest = dest;
				e.weight = weight;
				this->edges.push(e);
				vertex vs = this->vertices.get(src);
				vs.neighbors.push(dest);
				this->vertices.set(src, vs);
				vertex vd = this->vertices.get(dest);
				vd.neighbors.push(src);
				this->vertices.set(dest, vd);
			}
			/*
			* Removes an edge from the graph.
			*/
			void removeEdge(int src, int dest) {
				int i = 0;
				while(this->edges.get(i).src != src || this->edges.get(i).dest != dest)
					i++;
				this->edges.remove(i);
				i = 0;
				while(this->vertices.get(src).neighbors.get(i).integer != dest)
					i++;
				vertex v = this->vertices.get(src);
				v.neighbors.remove(i);
				this->vertices.set(src, v);
				i = 0;
				while(this->vertices[dest].neighbors[i] != src)
					i++;
				this->vertices[dest].neighbors[i] = -1;
			}
	};
};
