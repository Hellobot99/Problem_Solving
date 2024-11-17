#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

class Node {
public:
    int value;
    Node(int value);
    Node();
};

Node::Node() {
    this->value = 0;
}

Node::Node(int value) {
    this->value = value;
}

class Graph {
private:
    map<int, Node> nodes;
    int size;
    int** adjMatrix;
    int getNodeIndex(int value);

public:    
    Graph(int size);
    ~Graph();
    void addNode(int value);
    void addEdge(int from, int to, int weight);
    void display();
    void Floyd();
};

Graph::Graph(int size) : size(size) {
    adjMatrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        adjMatrix[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < size; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

int Graph::getNodeIndex(int value) {
    int index = 0;
    for (auto node : nodes) {
        if (node.first == value) {
            return index;
        }
        index++;
    }
    return -1;
}

void Graph::addNode(int value) {
    if (nodes.find(value) == nodes.end()) {
        nodes[value] = Node(value);
    }
    else {
        cout << "Node " << value << " already exists." << endl;
    }
}

void Graph::addEdge(int from, int to, int weight) {
    int fromIndex = getNodeIndex(from);
    int toIndex = getNodeIndex(to);
    if(adjMatrix[fromIndex][toIndex]==INT_MAX)
        adjMatrix[fromIndex][toIndex] = weight;
    else if(adjMatrix[fromIndex][toIndex]!=INT_MAX && adjMatrix[fromIndex][toIndex]>weight)
        adjMatrix[fromIndex][toIndex] = weight;    
}

void Graph::display() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (adjMatrix[i][j] == INT_MAX) {
                cout << "INF ";
            }
            else {
                cout << " " << adjMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void Graph::Floyd() {
    int** distance = new int* [size];
    for (int i = 0; i < size; ++i) {
        distance[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            distance[i][j] = adjMatrix[i][j];
        }
    }
    for (int k = 0; k < size; k++)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (distance[i][j] == INT_MAX) {
                cout << "0 ";
            }
            else {
                cout << distance[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int n, m, a, b, c;
	cin >> n >> m;
    Graph g(n);
    for (int i = 1; i < n + 1; i++) {
        g.addNode(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    
    g.Floyd();
}