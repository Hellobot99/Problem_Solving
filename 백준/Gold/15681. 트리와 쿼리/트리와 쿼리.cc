#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

typedef struct node {
	int value;
	vector<node*> childs;
}node;

node* create_node(int a) {
	node* new_node = new node;
	new_node->value = a;
	new_node->childs.clear();
	return new_node;
}

void countsubtreenode(node* root, vector<int> &size, int n, int p){
	for (int i = 0; i < root->childs.size(); i++) {
		int v = root->childs[i]->value;
		if (v != p) {
			countsubtreenode(root->childs[i], size, v, n);
			size[n] += size[v];
		}
	}
}

int main() {

	int N, R, Q, u, v, c = 0, a;
	scanf("%d %d %d", &N, &R, &Q);

	vector<int> size(N + 1, 1);
	vector<node*> vec(N + 1);

	for (int i = 1; i <= N; i++) {
		vec[i] = create_node(i);
	}

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		vec[u]->childs.push_back(vec[v]);
		vec[v]->childs.push_back(vec[u]);
	}

	countsubtreenode(vec[R], size, R, -1);

	for (int i = 0; i < Q; i++) {
		scanf("%d", &a);
		printf("%d\n", size[a]);
	}

	return 0;
}