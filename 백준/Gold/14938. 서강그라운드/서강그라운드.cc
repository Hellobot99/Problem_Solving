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
    int item;
    Node(int value, int item);
    Node();
};

Node::Node() {
    this->value = 0;
}

Node::Node(int value, int item) {
    this->value = value;
    this->item = item;
}

class Graph {
private:
    map<int, Node> nodes;
    map<int, vector<pair<int, int>>> adjacencyList;
    vector<tuple<int, int, int>> edges;

public:
    void addNode(int value, int item);
    void addEdge(int from, int to, int weight);
    void display();
    int dijkstra(int start, int ma);
};


void Graph::addNode(int value, int item) {
    if (nodes.find(value) == nodes.end()) {
        nodes[value] = Node(value, item);
    }
    else {
        cout << "Node " << value << " already exists." << endl;
    }
}

void Graph::addEdge(int from, int to, int weight) {

    adjacencyList[from].push_back({ to, weight });
    adjacencyList[to].push_back({ from, weight });
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


int Graph::dijkstra(int start, int ma) {
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
    int result = 0;
    for (auto iter = distances.begin(); iter != distances.end(); iter++) 
        if ((iter->second) <= ma) result += nodes[iter->first].item;
    return result;

}

int main() {
    Graph g;
    
    int n, m, r, item, a, b, c, result = 0;
    cin >> n >> m >> r;
    for (int i = 1; i < n + 1; i++) {
        cin >> item;
        g.addNode(i, item);
    }
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    for (int i = 1; i < n + 1; i++) {
        a = g.dijkstra(i, m);
        if(result < a) result = a;
    }
    
    cout << result;
        
    return 0;
}

