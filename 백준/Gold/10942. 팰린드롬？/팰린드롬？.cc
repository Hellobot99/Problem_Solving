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

void solve(vector<int> arr, vector<vector<int>>& p) {
	for (int i = 1; i < arr.size(); i++) {
		for (int k = 1; k <= i; k++) {
			int size = i - k + 1;
			int middle = (k + i) / 2;
			if (size == 1) {
			}
			else if (size == 2) {
				if (arr[i] == arr[k]) p[k][i] = 1;
				continue;
			}
			else if (arr[i] == arr[k] && p[k + 1][i - 1]) p[k][i] = 1;
			//cout << k << " " << i << " " << p[k][i]<< endl;
		}
	}
}

void print_arr(vector<vector<int>> p) {
	for (int i = 0; i < p.size(); i++) {
		for (int k = 0; k < p.size(); k++) {
			cout << p[i][k] << " ";
		}
		cout << endl;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, a, M, b;
	vector<int> arr;

	cin >> N;

	arr.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr.push_back(a);
	}

	vector<vector<int>> p(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i < p.size(); i++) {
		p[i][i] = 1;
	}

	solve(arr, p);

	//print_arr(p);	
	
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << p[a][b] << "\n";
	}
	

	return 0;
}