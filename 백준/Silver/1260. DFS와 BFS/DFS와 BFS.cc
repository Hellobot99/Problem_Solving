#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
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
public:
    map<int, Node> nodes;
    map<int, vector<int>> adjacencyList;
    void addNode(int value);
    void addEdge(int from, int to);
    void display();
    void DFS(int value, vector<int>& visited);
    void BFS(int value, vector<int>& visited);
};

void Graph::addNode(int value) {
    if (nodes.find(value) == nodes.end()) {
        nodes[value] = Node(value);
    }
    else {
        cout << "Node " << value << " already exists." << endl;
    }
}

void Graph::addEdge(int from, int to) {
    adjacencyList[from].push_back(to);
    adjacencyList[to].push_back(from);
}

void Graph::display() {
    for (auto& pair : adjacencyList) {
        cout << "Node " << pair.first << " is connected to: ";
        for (auto& neighbor : pair.second) {
            cout << "(" << neighbor << ") ";
        }
        cout << endl;
    }
}

void Graph::DFS(int value, vector<int>& visited) {
    visited.push_back(value);
    cout << value << " ";
    for (auto iter = adjacencyList[value].begin(); iter != adjacencyList[value].end(); iter++) {
        if (find(visited.begin(), visited.end(), *iter) == visited.end()) DFS(*iter, visited);
    }
}

void Graph::BFS(int value, vector<int>& visited) {
    queue<int> q;
    int current;
    visited.push_back(value);
    q.push(value);
    while (!q.empty()) {
        current = q.front();
        cout << current << " ";
        q.pop();
        for (auto iter = adjacencyList[current].begin(); iter != adjacencyList[current].end(); iter++) {
            if (find(visited.begin(), visited.end(), *iter) == visited.end()) {
                visited.push_back(*iter);
                q.push(*iter);
            }
        }
    }
}

bool compare(int& a, int& b) {
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Graph g;
    vector<int>visited;
    int n, m, start, a, b;
    cin >> n >> m >> start;
    for (int i = 1; i < n + 1; i++)
        g.addNode(i);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g.addEdge(a,b);
    }
    for (auto iter = g.adjacencyList.begin(); iter != g.adjacencyList.end(); iter++) {
        sort(iter->second.begin(), iter->second.end(), compare);
    }
    g.DFS(start, visited);
    visited.clear();
    cout << "\n";
    g.BFS(start, visited);

    return 0;
}