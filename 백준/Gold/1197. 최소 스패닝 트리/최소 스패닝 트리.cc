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
    int kruskal();
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

int Graph::kruskal() {
    sort(edges.begin(), edges.end());
    UnionFind uf(nodes.size() + 1);

    int mstWeight = 0;
    vector<tuple<int, int, int>> mstEdges;

    for (auto& edge : edges) {
        int weight, u, v;
        tie(weight, u, v) = edge;

        if (uf.find_Union(u) != uf.find_Union(v)) {
            uf.unite(u, v);
            mstEdges.push_back(edge);
            mstWeight += weight;
        }
    }
    for (auto& edge : mstEdges) {
        int weight, u, v;
        tie(weight, u, v) = edge;
    }
    return mstWeight;
}

int main() {
    Graph g;

    int v, e, a, b, c;
    cin >> v >> e;
    for (int i = 1; i < v + 1; i++) {
        g.addNode(i);
    }
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }

    cout << g.kruskal();

    return 0;
}

