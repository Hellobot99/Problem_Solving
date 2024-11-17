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

public:
    void addNode(int value);
    void addEdge(int from, int to, int weight);
    void display();
    void DFS(int value, vector<int>& visited);
    void BFS(int value, vector<int>& visited);
    int dijkstra(int start, int end);
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
    adjacencyList[from].push_back({ to, weight });
}

int Graph::dijkstra(int start, int end) {
    map<int, int> distances;
    for (auto& node : nodes) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentDistance > distances[currentNode]) continue;

        for (auto& neighbor : adjacencyList[currentNode]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (distances[currentNode] + edgeWeight < distances[nextNode]) {
                distances[nextNode] = distances[currentNode] + edgeWeight;
                pq.push(make_pair(distances[nextNode], nextNode));
            }
        }
    }

    return distances[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Graph g;

    int n, m, a, b, c, start, end;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++) {
        g.addNode(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    cin >> start >> end;

    cout << g.dijkstra(start, end);

    return 0;
}