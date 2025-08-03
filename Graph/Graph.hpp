#pragma once
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
        Type data;
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

    int getVertexCount() const{
        return vertexCount;
    }

    int getEdgeCount() const{
        return edgeCount;
    }

    int getDegreeCount() const{
        return edgeCount*2;
    }

    // Adds Vertex to graph
    void addVertex(Type data, std::string name = "") {
        int newID = adjList.getSize();
        Vertex v{newID, data, name};
        vertices.append(v);
        adjList.append(Vector<Edge>());
        vertexCount++;
    }

    // Adds Vertex to graph
    void addEdge(int from, int to, double weight = 1.0, std::string name = "") {
        assert(vertices.getSize() <= from || vertices.getSize() <= to);
        Edge e{to, weight, name};
        adjList[from].append(e);
        edgeCount++;
    }


};