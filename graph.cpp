namespace graph {
	class vertex {
		public:
			int edges[]; 
			vertex(int* edges, int size) {
				for (int i=0; i < size; i++) {
					this->edges[i] = edges[i];
				}
			}
	};
	class edge {
		public:
			vertex* start;
			vertex* end;
			edge(vertex* start, vertex* end) {
				this->start = start;
				this->end = end;
			}
	};
};
