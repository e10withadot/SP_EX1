#include "graph.hpp"
#include "data_strct.hpp"
using namespace data;
#include <iostream>

void graph::graph::addEdge(int src, int dest, int weight) {
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
void graph::graph::removeEdge(int src, int dest) {
	int i = 0;
	while(this->edges.get(i).src != src || this->edges.get(i).dest != dest)
		i++;
	this->edges.remove(i);
	i = 0;
	while(this->vertices.get(src).neighbors.get(i) != dest)
		i++;
	vertex v = this->vertices.get(src);
	v.neighbors.remove(i);
	this->vertices.set(src, v);
	i = 0;
	while(this->vertices.get(dest).neighbors.get(i) != src)
		i++;
	v = this->vertices.get(dest);
	v.neighbors.remove(i);
	this->vertices.set(dest, v);
}
void graph::graph::print_graph() {
	for (int i = 0; i < this->vertices.size; i++) {
		list<int> neighbors = this->vertices.get(i).neighbors;
		std::cout << "Vertex " << i << " neighbors: ";
			for (int j = 0; j < neighbors.size; j++) {
				std::cout << neighbors.get(j) << ", ";
			}
			std::cout << "\n";
	}
}
