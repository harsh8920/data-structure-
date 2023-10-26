#include <iostream>
#include <vector>
 using namespace std;

// Class to represent a graph as an adjacency list.
class Graph {
public:
    // Constructor to initialize the number of vertices.
    Graph(int numVertices) : V(numVertices) {
        adjList.resize(V);
    }

    // Function to add an edge to the graph.
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // For an undirected graph.
    }

    // Function to print the adjacency list representation of the graph.
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "Adjacency list of vertex " << v << ": ";
            for (int neighbor : adjList[v]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

private:
    int V; // Number of vertices.
    vector<std::vector<int>> adjList; // Adjacency list.
};

int main() {
    int numVertices = 5; // Define the number of vertices in the graph.

    // Create a graph with 5 vertices.
    Graph graph(numVertices);

    // Add edges to the graph.
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency list representation of the graph.
    graph.printGraph();

    return 0;
}
