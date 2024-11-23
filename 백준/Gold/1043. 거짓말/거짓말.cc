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
    void DFS(int value, set<int>& visited);
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
int c = 0;
void Graph::DFS(int value, set<int>& visited) {
    visited.insert(value);
    c++;
    for (auto iter = adjacencyList[value].begin(); iter != adjacencyList[value].end(); iter++) {
        if (find(visited.begin(), visited.end(), iter->first) == visited.end())
            DFS(iter->first, visited);
    }
}

int main() {
    Graph g;
    int n, m, a, b, f, result = 0;
    set<int>visited;    
    cin >> n >> m;
    vector<vector<int>>list(m);
    for (int i = 0; i < n + 1; i++) 
        g.addNode(i);
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        g.addEdge(0, b, 1);
    }
    for (int i = 0; i < m; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            if (j == 0)f = b;
            else g.addEdge(b, f, 1);
            list[i].push_back(b);
        }
    }
    bool pass;
    g.DFS(0, visited);
    for (auto iter = list.begin(); iter != list.end(); iter++) {
        pass = false;
        for (auto it = iter->begin(); it != iter->end(); it++) {
            if (visited.find(*it) != visited.end()) {
                pass = true;
                break;
            }
        }
        if (!pass) result++;
    }

    cout << result;

    return 0;
            
}