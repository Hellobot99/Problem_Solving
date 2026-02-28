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

	int t, n, input;

	cin >> t;

	for (int z = 0; z < t; z++) {
		cin >> n;
		int min = INT_MAX, max = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> input;
			if (min > input) min = input;
			if (max < input) max = input;
		}
		cout << min << " " << max << endl;
	}

	return 0;
}