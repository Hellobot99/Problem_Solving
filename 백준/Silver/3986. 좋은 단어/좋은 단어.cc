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

int solve(string s) {
	stack<int> stack;
	for (int i = 0; i < s.size(); i++) {
		if (stack.empty()) stack.push(s[i]);
		else if (stack.top() == s[i]) stack.pop();
		else stack.push(s[i]);
	}
	return stack.empty();
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int N, r = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (solve(s)) r++;
	}

	cout << r;

	return 0;
}