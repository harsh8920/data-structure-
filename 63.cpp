#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void DFS(int startVertex);

private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
    void DFSUtil(int vertex, std::vector<bool>& visited);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::DFSUtil(int vertex, std::vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int adjacentVertex : adjacencyList[vertex]) {
        if (!visited[adjacentVertex]) {
            DFSUtil(adjacentVertex, visited);
        }
    }
}

void Graph::DFS(int startVertex) {
    vector<bool> visited(numVertices, false);

    DFSUtil(startVertex, visited);
}

int main() {
    Graph graph(8); // Create a graph with 8 vertices.

    // Add edges to the graph.
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(3, 7);

    cout << "Depth-First Traversal (starting from vertex 0): ";
    graph.DFS(0);

    return 0;
}
