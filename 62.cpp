#include <iostream>
#include <vector>
#include <queue>
 using namespace std;
 
class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int startVertex);

private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::BFS(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    std::queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        std::cout << currentVertex << " ";
        queue.pop();

        for (int adjacentVertex : adjacencyList[currentVertex]) {
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                queue.push(adjacentVertex);
            }
        }
    }
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

   
}
