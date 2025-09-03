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

typedef long long ll;

ll cal(vector<ll> sum, vector<ll> arr, int s, int e1, int e2) {
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

void solve(vector<ll> sum, vector<ll> arr, int N) {
	ll m = 0;
	ll e;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			//0 k N-1
			for (int k = 1; k < N - 1; k++) {
				e = sum[k - 1] + sum[N - 2] - arr[k];
				if (e > m) m = e;
			}
			//cout << e << "a" << endl;
		}
		else if (i == N - 1) {
			//0 k N-1
			for (int k = 1; k < N - 1; k++) {
				e = sum[i] - sum[k] + sum[i] - sum[0] - arr[k];
				if (e > m) m = e;
			}
			//cout << e << "b" << endl;
		}
		else {
			//0 i N-1
			e = sum[N - 2] - sum[0] + arr[i];
			if (e > m) m = e;
			//cout << e << "c" << endl;

		}
	}

	cout << m << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	ll a;
	cin >> N;
	vector<ll> arr;
	vector<ll> sum;
	
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