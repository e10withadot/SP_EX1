#include <iostream>
#include "algorithms.hpp"
#include "data_strct.hpp"
using namespace data;
#include "graph.hpp"
using namespace graph;

void printPath(list<int>& path) {
    std::cout << "Path: ";
    for (int i = 0; i < path.size; i++) {
        std::cout << path.get(i) << " ";
    }
    std::cout << "\n";
}

void printMST(list<edge>& mst) {
    std::cout << "MST edges:" << "\n";
    for (int i = 0; i < mst.size; i++) {
        edge e = mst.get(i);
        std::cout << "(" << e.src << " - " << e.dest << ") weight: " << e.weight << "\n";
    }
}

int main() {
    // Create a graph with 6 vertices
    Graph g(6);
    
    // Add edges to create a sample graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    std::cout << "Original graph structure:" << "\n";
    g.print_graph();
    std::cout << "\n";

    list<vertex> vertices = g.getVertices();
    std::cout << "BFS traversal starting from vertex 0:" << "\n";
    list<int> bfs_result = algorithms::bfs(vertices);
    printPath(bfs_result);
    std::cout << "\n";

    std::cout << "DFS traversal starting from vertex 0:" << "\n";
    list<int> dfs_result = algorithms::dfs(vertices);
    printPath(dfs_result);
    std::cout << "\n";

    std::cout << "Dijkstra's shortest paths from vertex 0:" << "\n";
    list<int> distances = algorithms::dijkstra(g, 0);
    for (int i = 0; i < distances.size; i++) {
        std::cout << "Distance to vertex " << i << ": " << distances.get(i) << "\n";
    }
    std::cout << "\n";

    std::cout << "Prim's MST Algorithm:" << "\n";
    list<edge> prim_mst = algorithms::prim(g);
    printMST(prim_mst);
    std::cout << "\n";
    
    std::cout << "Kruskal's MST Algorithm:" << "\n";
    list<edge> kruskal_mst = algorithms::kruskal(g);
    printMST(kruskal_mst);

    return 0;
}
