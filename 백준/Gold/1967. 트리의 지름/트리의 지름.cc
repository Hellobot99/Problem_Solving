#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode(int value);
    TreeNode();
};

TreeNode::TreeNode() {
    this->value = 0;
}

TreeNode::TreeNode(int value) {
    this->value = value;
}

class Tree {
private:
    map<int, TreeNode> nodes;
    map<int, vector<pair<int ,int>>> children;
    map<int, int> parent;

public:
    void addNode(int value);
    void addChild(int parentValue, int childValue, int weight);
    int len(int value = 1);
};

void Tree::addNode(int value) {
    TreeNode newnode(value);
    nodes[value] = newnode;
}

void Tree::addChild(int parentValue, int childValue, int weight) {
    children[parentValue].push_back(make_pair(childValue,weight));

    addNode(childValue);
    parent[childValue] = parentValue;
}

vector<pair<int, int>>length;
int Tree::len(int value) {
    int max = 0;
    int sec = 0;
    int a;
    if (nodes.find(value) == nodes.end()) return -1;

    for (vector<pair<int, int>>::iterator iter = children[value].begin(); iter != children[value].end(); iter++) {
        a = len(iter->first) + iter->second;
        if (a > max) {
            sec = max;
            max = a;
        }
        else if (a > sec && a <= max) sec = a;
    }
    length.push_back(make_pair(value, max+sec));
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Tree tree;
    tree.addNode(1);
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        tree.addChild(a, b, c);
    }

    tree.len(1);
    int max = 0;
    for (auto iter = length.begin(); iter != length.end(); iter++) {
        if (max < iter->second) max = iter->second;
    }
    cout << max;
    return 0;
}