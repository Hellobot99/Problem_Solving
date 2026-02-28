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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, min = INT_MAX, sum = 0;
	vector<int> v(10001, 1);
	vector<int> list;
	for (int i = 2; i < 10001; i++) {
		if (v[i]) {
			list.push_back(i);
			for (int k = i + 1; k < 10001; k++)
				if (v[k] && k % i == 0) v[k] = 0;
		}
	}

	cin >> m >> n;

	for (auto iter = list.begin(); iter != list.end(); iter++) {
		int a = *iter;
		if (a >= m && a <= n) {
			if (min > a) min = a;
			sum += a;
		}
		if (a > n) break;
	}

	if (sum == 0) cout << "-1";
	else cout << sum << endl << min;
		
	return 0;
}