#define DOCTEST_CONFIG
#include "doctest.h"
#include "algorithms.hpp"
using namespace graph;
#include "data_strct.hpp"

TEST_CASE("Testing BFS algorithm") {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    list<vertex> vertices = g.getVertices();
    list<int> bfs_result = algorithms::bfs(vertices);

    CHECK(bfs_result.size == 6);
    CHECK(bfs_result.get(0) == 0);
}

TEST_CASE("Testing DFS algorithm") {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    list<vertex> vertices = g.getVertices();
    list<int> dfs_result = algorithms::dfs(vertices);

    CHECK(dfs_result.size == 6);
    CHECK(dfs_result.get(0) == 0);
}

TEST_CASE("Testing Dijkstra's algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 5);

    list<int> distances = algorithms::dijkstra(g, 0);
    CHECK(distances.get(0) == 0);
    CHECK(distances.get(1) == 2);
    CHECK(distances.get(2) == 3);
    CHECK(distances.get(3) == 5);
}

TEST_CASE("Testing Prim's MST algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 5);

    list<edge> mst = algorithms::prim(g);
    CHECK(mst.size == 3);
    int total_weight = 0;
    for(int i = 0; i < mst.size; i++) {
        total_weight += mst.get(i).weight;
    }
    CHECK(total_weight == 6);
}

TEST_CASE("Testing Kruskal's MST algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 5);

    list<edge> mst = algorithms::kruskal(g);
    CHECK(mst.size == 3);
    int total_weight = 0;
    for(int i = 0; i < mst.size; i++) {
        total_weight += mst.get(i).weight;
    }
    CHECK(total_weight == 6);
}
