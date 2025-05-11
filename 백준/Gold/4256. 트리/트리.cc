#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <cmath>
using namespace std;

typedef struct node{
	int value;
	node* left_child;
	node* right_child;
}node;

node* create_node(int value);
void post_order(node* root);
int get_pre(vector<pair<int, bool>>& pre);
node* make_tree(vector<int>& pre, vector<int>& in, int n, int pre_s, int in_s);

int main() {

	int T, n, a;
	vector<int> pre, in;

	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> n;
		pre.clear();
		in.clear();
		for (int y = 0; y < n; y++) {
			cin >> a;
			pre.push_back(a);
		}
		for (int y = 0; y < n; y++) {
			cin >> a;
			in.push_back(a);
		}
		node* root = make_tree(pre, in, n, 0, 0);
		post_order(root);
		cout << endl;
	}

	return 0;
}

node* create_node(int value) {
	node* new_node = new node;
	new_node->value = value;
	new_node->left_child = new_node->right_child = NULL;
	return new_node;
}

void post_order(node* root) {
	if (root) {
		post_order(root->left_child);
		post_order(root->right_child);
		cout << root->value << " ";
	}
}

node* make_tree(vector<int>& pre, vector<int>& in, int n, int pre_s, int in_s) {
	if (n <= 0) return NULL;
	if (n == 1) return create_node(pre[pre_s]);

	int in_temp;

	for (int i = in_s; i < in_s + n; i++) {
		if (pre[pre_s] == in[i]) {
			in_temp = i;
			break;
		}
	}

	node* new_node = create_node(pre[pre_s]);

	//cout << pre[pre_s] << " / " << in_temp - in_s << " " << pre_s + 1 << " " << in_s << endl;
	new_node->left_child = make_tree(pre, in, in_temp - in_s, pre_s + 1, in_s);
	
	//cout << pre[pre_s] << " / " << n - in_temp - 1 << " " << pre_s + 1 + in_temp - in_s << " " << in_temp + 1 << endl;
	new_node->right_child = make_tree(pre, in, n - in_temp + in_s - 1, pre_s + 1 + in_temp - in_s, in_temp + 1);
	
	return new_node;
}