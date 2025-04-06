namespace graph {
	struct edge {
		int src;
		int dest;
		int weight = -1;
	};
	struct vertex {
		int* neighbors;
	};
	class graph {
		private:
			int max_vertices;
			edge* edges;
			vertex* vertices;
		public:
			graph(int max_vertices) {
				this->max_vertices = max_vertices;
				this->edges = new edge[6];
				this->vertices = new vertex[this->max_vertices];
				for (int i = 0; i < max_vertices; i++) {
					this->vertices[i].neighbors = new int[max_vertices];
					for (int j = 0; j < max_vertices; j++) {
						this->vertices[i].neighbors[j] = -1;
					}
				}
			}
			/*
			* Adds an edge to the graph.
			*/
			void addEdge(int src, int dest, int weight = 1) {
				int i = 0;
				while(this->edges[i].weight >= 0)
					i++;
				this->edges[i].src = src;
				this->edges[i].dest = dest;
				this->edges[i].weight = weight;
				i = 0;
				while (this->vertices[dest].neighbors[i] >= 0)
					i++;
				this->vertices[dest].neighbors[i] = src;
				i = 0;
				while (this->vertices[src].neighbors[i] >= 0)
					i++;
				this->vertices[src].neighbors[i] = dest;
			}
			/*
			* Removes an edge from the graph.
			*/
			void removeEdge(int src, int dest) {
				int i = 0;
				while(this->edges[i].src != src || this->edges[i].dest != dest)
					i++;
				delete this->edges[i];
				i = 0;
				while(this->vertices[src].neighbors[i] != dest)
					i++;
				this->vertices[src].neighbors[i] = -1;
				i = 0;
				while(this->vertices[dest].neighbors[i] != src)
					i++;
				this->vertices[dest].neighbors[i] = -1;
			}
	};
};
