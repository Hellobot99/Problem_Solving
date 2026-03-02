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

	vector<int> v(21, 0);

	v[1] = 1;

	for (int i = 2; i < 21; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}

	int input;
	cin >> input;
	cout << v[input];

	return 0;
}