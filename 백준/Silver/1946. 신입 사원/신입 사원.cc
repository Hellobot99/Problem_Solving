#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, a, b, min, result = 1;
	vector<pair<int, int>> arr;

	cin >> T;
	
	for (int q = 0; q < T; q++) {
		arr.clear();
		cin >> N;
		result = 1;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			arr.push_back(make_pair(a, b));
		}

		sort(arr.begin(), arr.end());
		min = arr[0].second;

		for (auto iter = arr.begin() + 1; iter != arr.end(); iter++) {
			if (iter->second < min) {
				min = iter->second;
				result++;
			}
		}
		cout << result <<endl;
	}
	return 0;
}