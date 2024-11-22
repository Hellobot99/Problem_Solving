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
private:
    map<int, Node> nodes;
    map<int, vector<pair<int, int>>> adjacencyList;
    vector<tuple<int, int, int>> edges;

public:
    void addNode(int value);
    void addEdge(int from, int to, int weight);
    void display();
    void prim(int start, set<int>& visited);
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int find_Union(int x) {
        if (parent[x] != x) {
            parent[x] = find_Union(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find_Union(x);
        int rootY = find_Union(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void Graph::addNode(int value) {
    if (nodes.find(value) == nodes.end()) {
        nodes[value] = Node(value);
    }
    else {
        cout << "Node " << value << " already exists." << endl;
    }
}

void Graph::addEdge(int from, int to, int weight) {
    if (nodes.find(from) == nodes.end()) {
        addNode(from);
    }
    if (nodes.find(to) == nodes.end()) {
        addNode(to);
    }
    adjacencyList[from].push_back({ to, weight });
    adjacencyList[to].push_back({ from, weight });
    edges.push_back({ weight, from, to });
}

void Graph::display() {
    for (auto& pair : adjacencyList) {
        cout << "Node " << pair.first << " is connected to: ";
        for (auto& neighbor : pair.second) {
            cout << "(" << neighbor.first << ", weight: " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

void Graph::prim(int start, set<int>& visited) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<tuple<int, int, int>> mstEdges;
    int mstWeight = 0;

    for (auto& neighbor : adjacencyList[start]) {
        pq.push({ neighbor.second, {start, neighbor.first} });
    }
    visited.insert(start);

    while (!pq.empty()) {
        auto nodes = pq.top().second;
        auto weight = pq.top().first;
        int from = nodes.first, to = nodes.second;
        pq.pop();

        if (visited.find(to) != visited.end()) continue;

        visited.insert(to);
        mstWeight += weight;
        mstEdges.push_back({ from, to, weight });

        for (auto& neighbor : adjacencyList[to]) {
            if (visited.find(neighbor.first) == visited.end()) {
                pq.push({ neighbor.second, {to, neighbor.first} });
            }
        }
    }

    cout << mstWeight << endl;
}

int main() {
    Graph g;
    
    int n, e, a, b, c;
    cin >> n >> e;
    for (int i = 1; i < n + 1; i++)
        g.addNode(i);
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    set<int>visited;
    g.prim(a, visited);

    return 0;
}

