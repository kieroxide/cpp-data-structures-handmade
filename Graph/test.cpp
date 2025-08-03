#include "../Graph/Graph.hpp"
#include <iostream>

int main(){
    Graph<int> g;
    g.addVertex(1);
    g.addVertex(10, "Ten");
    g.addVertex(100, "Hundred");

    g.addEdge(0, 1, 10, "x10");
    g.addEdge(0, 2, 100, "x100");
    g.addEdge(1, 2, 10, "x10");

    assert(g.getVertexCount() == 3);
    assert(g.getEdgeCount() == 3);
    assert(g.getDegreeCount() == 6);

    std::cout << g;
    return 0;
}