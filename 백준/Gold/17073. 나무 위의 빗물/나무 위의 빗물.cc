#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

typedef struct {
	int data;
	vector<int> adj;
} node;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 
	
	int N, W, a, b, U, V;
	cin >> N >> W;

	vector<node> tree;

	for (int i = 0; i <= N; i++) {
		node z;
		z.data = i;
		tree.push_back(z);
	}

	for (int i = 1; i < N; i++) {
		cin >> U >> V;
		tree[U].adj.push_back(V);
		tree[V].adj.push_back(U);
	}

	int sum = 0;

	for (int i = 2; i <= N; i++) {
		if (tree[i].adj.size() == 1)
			sum++;
	}

	printf("%.10lf", (double)W / (double)sum);

	return 0;
}