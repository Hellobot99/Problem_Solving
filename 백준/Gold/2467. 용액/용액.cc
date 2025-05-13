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

int check(int a, int b) {
	if (a + b < 0) return -(a + b);
	return a + b;

}

pair<pair<int, int>, int> solve(vector<int> arr, int n) {
	pair<pair<int, int>, int> min;
	int index1 = 0, index2 = n - 1;
	min.first.first = arr[index1];
	min.first.second = arr[index2];
	min.second = check(arr[index1], arr[index2]);

	while (index1 < index2) {
		int sum = check(arr[index1], arr[index2]);
		if (sum == 0) {
			min.first.first = arr[index1];
			min.first.second = arr[index2];
			min.second = sum;
			return min;
		}
		else if (sum < min.second) {
			min.first.first = arr[index1];
			min.first.second = arr[index2];
			min.second = sum;
		}
		else if (arr[index1] + arr[index2] > 0) {
			index2--;
		}
		else {
			index1++;
		}
	}
	
	return min;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a;
	vector<int> arr;
	pair<pair<int, int>, int> result;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr.push_back(a);
	}

	result = solve(arr, N);

	cout << result.first.first << " " << result.first.second;

	return 0;
}