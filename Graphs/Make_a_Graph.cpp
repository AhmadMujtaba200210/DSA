//
// Created by Mac on 10/10/2023.
//
#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adjList; // Adjacency list representation

public:
     explicit Graph(int vertices){
        V = vertices;
        adjList = new list<int>[vertices];
    }

    void addEdge(int source, int destination, bool undirected=true) {
        adjList[source].push_back(destination);
        // For an undirected graph, you can add the reverse edge too:
        if (undirected)
        adjList[destination].push_back(source);
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            std::cout << i << " --> ( ";
            for (int vertex : adjList[i]) {
                cout << vertex << " ";
            }
            cout << ")" <<std::endl;
        }
    }
};

int main() {
    // number of nodes
    int vertices = 5;
    Graph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    return 0;
}
