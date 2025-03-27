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

string result;

int solve(stack<int>& s, vector<int>& arr) {
	int idx = 1;
	int size = arr.size();
	for (int i = 0; i < arr.size(); i++) {
		while (s.empty() || (arr[i] > s.top() && idx <= size)) {
			s.push(idx);
			idx++;
			result+='+';
		}
		if (arr[i] == s.top()) {
			result += '-';
			s.pop();
		}
		else {
			return 0;
		}
	}
	return 1;
}

void print_string(string result) {
	for (int i = 0; i < result.size(); i++)
		cout << result[i] <<"\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	stack<int> s;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (solve(s,arr)) print_string(result);
	else cout << "NO";
	 
	return 0;
}