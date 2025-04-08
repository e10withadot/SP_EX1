// ey.gellis@gmail.com
#include <stdexcept>
#include "graph.hpp"
using namespace graph;
#include <iostream>

list<vertex> Graph::getVertices() {
	return this->vertices;
}

list<edge> Graph::getEdges() {
	return this->edges;
}

void Graph::addEdge(int src, int dest, int weight) {
	edge e;
	e.src = src;
	e.dest = dest;
	e.weight = weight;
	this->edges.push(e);
	vertex vs;
	try {
		vs = this->vertices.get(src);
	}
	catch(std::invalid_argument&) {
		vs = vertex();
	}
	vs.neighbors.push(dest);
	this->vertices.set(src, vs);
	vertex vd;
	try {
		vd = this->vertices.get(dest);
	}
	catch(std::invalid_argument&) {
		vd = vertex();
	}
	vd.neighbors.push(src);
	this->vertices.set(dest, vd);
}
void Graph::removeEdge(int src, int dest) {
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
void Graph::print_graph() {
	for (int i = 0; i < this->vertices.getSize(); i++) {
		list<int> neighbors;
		try {
			neighbors = this->vertices.get(i).neighbors;
		}
		catch(std::invalid_argument&) {
			neighbors = list<int>();
		}
		std::cout << "Vertex " << i << " neighbors: ";
			for (int j = 0; j < neighbors.getSize(); j++) {
				int n;
				try {
					n = neighbors.get(j);
					std::cout << n << ", ";
				}
				catch(std::invalid_argument&){
					continue;
				}
			}
			std::cout << "\n";
	}
}
