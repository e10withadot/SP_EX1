namespace graph {
	class vertex {
		public:
			int edges[]; 
			vertex(int edges[]) {
				int length = sizeof(edges)/sizeof(int);
				for (int i=0; i < length; i++) {
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
