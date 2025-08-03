#include <cassert>
#include <iostream>

#include "../Vector/Vector.hpp"

template <typename Type>
class Graph
{
   private:
    struct Vertex
    {
        int id = -1;
        std::string name;
    };
    struct Edge
    {
        int to;
        double weight = 1.0;
        std::string name;
        int id = -1;
    };

    Vector<Vertex> vertices;
    Vector<Vector<Edge>> adjList;

    int vertexCount;
    int edgeCount;

   public:
    // Default constructor
    Graph() {
        adjList.resize(0);
        vertexCount = 0;
        edgeCount   = 0;
    }

    // Adds Vertex to graph
    void addVertex(std::string name = "") {
        int newID = adjList.getSize();
        Vertex v{newID, name};
        vertices.append(v);
        adjList.append(Vector<Edge>());
    }

    // Adds Vertex to graph
    void addEdge(int from, int to, double weight = 1.0, std::string name = "", int edgeID = edgeCount) {
        assert(vertices.getSize() <= from || vertices.getSize() <= to);
        Edge e{to, weight, name, id};
        adjList[from][to] = 1;
    }


};