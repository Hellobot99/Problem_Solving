#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
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
    map<int, vector<pair<int, int>>> adjacencyList;

public:
    void addNode(int value);
    void addEdge(int from, int to, int weight);
    void display();
    void DFS(int value, set<int>& visited, int len);
};

void Graph::addNode(int value) {
    if (nodes.find(value) == nodes.end()) {
        nodes[value] = Node(value);
    }
    else return;
}

void Graph::addEdge(int from, int to, int weight) {    
    adjacencyList[from].push_back({ to, weight });
}

int result=0;
int last;
void Graph::DFS(int value, set<int>& visited, int len) {
    visited.insert(value);
    if (len > result) {
        result = len;
        last = value;
    }
    for (auto iter = adjacencyList[value].begin(); iter != adjacencyList[value].end(); iter++) {
        if (visited.find(iter->first) == visited.end()) 
            DFS(iter->first, visited, len+iter->second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Graph g;
    set<int> visited;
    int v, a, b, c;
    cin >> v;
    for (int i = 1; i < v + 1; i++) {
        g.addNode(i);
    }
    for (int i = 1; i < v + 1; i++) {
        cin >> a;
        while (1) {
            cin >> b;
            if (b == -1)break;
            cin >> c;
            g.addEdge(a, b, c);
        }
    }

    g.DFS(1, visited, 0);    
    visited.clear();
    g.DFS(last, visited, 0);
       
    cout << result;
    return 0;
}