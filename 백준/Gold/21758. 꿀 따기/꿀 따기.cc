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

int cal(vector<int> sum, vector<int> arr, int s, int e1, int e2) {
	if (s > e1) {
		if(s > e2){
			if (e1 > e2) {
				// e2 e1 s
				return sum[s] + sum[s] - sum[e1] - sum[e2] - arr[e1];
			}
			else {
				// e1 e2 s
				return sum[s] + sum[s] - sum[e1] - sum[e2] - arr[e2];
			}
		}
		else {
			// e1 s e2
			return arr[s] - sum[e1] + sum[e2] - arr[e2];
		}
	}
	else {
		if (s < e2) {
			if (e1 > e2) {
				// s e2 e1
				return sum[e1] - sum[s] + arr[s] - arr[e1] + sum[e2] - sum[s] + arr[s] - arr[e2] - arr[e2];
			}
			else {
				// s e1 e2
				return sum[e1] - sum[s] + arr[s] - arr[e1] + sum[e2] - sum[s] + arr[s] - arr[e2] - arr[e1];
			}
		}
		else {
			// e2 s e1
			return arr[s] - sum[e2] + sum[e1] - arr[e1];
		}
	}
}

void solve(vector<int> sum, vector<int> arr, int N) {
	int e, m = 0;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			if (i == k) continue;
			for (int j = 0; j < N; j++) {
				if (k == j) continue;
				e = cal(sum, arr, i, j, k);
				//cout << e << ";" << endl;
				if (e > m) m = e;
			}
		}
	}

	cout << m << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a;
	cin >> N;
	vector<int> arr;
	vector<int> sum;
	
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr.push_back(a);
		
		if (i != 0) {
			sum.push_back(sum[i - 1] + a);
		}
		else {
			sum.push_back(a);
		}
	}

	solve(sum, arr, N);

	return 0;
}