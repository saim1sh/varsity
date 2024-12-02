#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int vertex;
    Node* next;
};

struct Graph {
    int numVertices;
    vector<int> visited;
    vector<Node*> adjLists;
};

Node* createNode(int v) {
    Node* newNode = new Node();
    newNode->vertex = v;
    newNode->next = nullptr;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = new Graph();
    graph->numVertices = vertices;
    graph->adjLists.resize(vertices, nullptr);
    graph->visited.resize(vertices, 0);
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = 1;
    cout << "Visited " << vertex << endl;

    while (temp != nullptr) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        cout << "\nAdjacency list of vertex " << v << "\n";
        while (temp) {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

int main() {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);
    DFS(graph, 2);

    return 0;
}