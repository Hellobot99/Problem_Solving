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
    void dijkstra(int start, int end);
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

void Graph::DFS(int value, vector<int>& visited) {
    visited.push_back(value);
    cout << value << " ";
    for (auto iter = adjacencyList[value].begin(); iter != adjacencyList[value].end(); iter++) {
        if (find(visited.begin(), visited.end(), iter->first) == visited.end()) DFS(iter->first, visited);
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
            if (find(visited.begin(), visited.end(), iter->first) == visited.end()) {
                visited.push_back(iter->first);
                q.push(iter->first);
            }
        }
    }
}
map<int, int> distances;
void Graph::dijkstra(int start, int end) {    
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
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Graph g;

    int v, e, start, a, b, c;
    cin >> v >> e >> start;
    for (int i = 1; i < v + 1; i++) {
        g.addNode(i);
    }
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    g.dijkstra(start, v);
    for (int i = 1; i < v + 1; i++) {
        
        if (distances[i] == INT_MAX) {
            cout << "INF" << "\n";
        }
        else {
            cout << distances[i] << "\n";
        }
    }

    return 0;
}
