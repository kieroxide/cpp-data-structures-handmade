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

    //TODO Implement map from vertex name to id
    bool containsVertex(int id){
        return id < getVertexCount() && id >= 0;
    }

    Vector<Vertex> getVertices() const{
        return vertices;
    }
    Vector<Vector<Edge>> getAdjList() const{
        return adjList;
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
        assert(containsVertex(from) && containsVertex(to));
        Edge e{to, weight, name};
        adjList[from].append(e);
        edgeCount++;
    }

    // << operator for easy cout <<
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph){
        os << "Graph:\n";
        os << "Edges:";
        os << "[";
        // Adjacent List Print
        Vector<Vector<Edge>> adjList = graph.getAdjList();
        for(int i = 0; i < adjList.getSize(); i++){
            Vector<Edge> vertexEdges = adjList[i];
            for(int j = 0; j < vertexEdges.getSize(); j++){
                os << "[";
                os << "From: " << i << ", ";
                os << "To: " << vertexEdges[j].to << ", ";
                os << "Weight: " << vertexEdges[j].weight << ", ";
                os << "Name: " << vertexEdges[j].name << "]";
                if(j != vertexEdges.getSize() - 1){
                    os << ", ";
                }
            } 
        }
        os << "]";
        Vector<Vertex> vertices = graph.getVertices();
        os << "\n";
        os << "Vertices:";
        os << "[";
        for(int i = 0; i < vertices.getSize(); i++){
            os << "[ id: " << vertices[i].id;
            os << ", Data: " << vertices[i].data; 
            os << ", Name: " << vertices[i].name;        
            os << "]";
            if(i != vertices.getSize() - 1){
                os << ", ";
            }   
        }
        os << "]";
        return os;
    }
    
    void clearGraph(){
        vertices.clear();
        adjList.clear();
        vertexCount = 0;
        edgeCount = 0;
    }
};