#include <iostream>
#include <vector>
#include <map>
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
    map<int, vector<int>> children;
    map<int, int> parent;

public:
    void addNode(int value);
    void addChild(int parentValue, int childValue);
    void display(int rootValue = 0, int level = 0);
    void deleteNode(int value);
    void solve(int value, int& result);
};

void Tree::addNode(int value) {
    TreeNode newnode(value);
    nodes[value] = newnode;
}

void Tree::addChild(int parentValue, int childValue) {
    children[parentValue].push_back(childValue);
    addNode(childValue);
    parent[childValue] = parentValue;
}

void Tree::display(int rootValue, int level) {
    if (nodes.find(rootValue) == nodes.end()) return;
    cout << rootValue << "\n";
    for (vector<int>::iterator iter = children[rootValue].begin(); iter != children[rootValue].end(); iter++) {
        display(*iter, level + 1);
    }
}

void Tree::deleteNode(int value) {

    nodes.erase(value);
    for (int child : children[value]) {
        deleteNode(child);
    }

    if (parent.find(value) != parent.end()) {
        int parentValue = parent[value];
        vector<int>& pa = children[parentValue];
        for (int i = 0; i < pa.size(); i++) {
            if (pa[i] == value) {
                pa.erase(pa.begin() + i);
                break;
            }
        }
    }

    children.erase(value);
    parent.erase(value);
}

void Tree::solve(int value, int& result) {
    if (children.find(value) == children.end() || children[value].empty()) {
        result++;
    }
    else {
        for (auto iter = children[value].begin(); iter != children[value].end(); iter++) {
            solve(*iter, result);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int root;
    int n, a, result = 0;
    Tree tree;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == -1) {
            tree.addNode(a);
            root = i;
        }
        else tree.addChild(a, i);
    }
    cin >> a;
    if (a!=root) {
        tree.deleteNode(a);
        
        tree.solve(root, result);
        cout << result;
    }
    else cout << "0";   

    return 0;
}