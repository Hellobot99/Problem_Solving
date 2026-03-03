#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	int n;
	

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, input);

		vector<int> v(27, 0);
		pair<char, int> max = { ' ',INT_MIN };
		
		for (int k = 0; k < input.size(); k++) {
			if (input[k] == ' ') continue;
			int a = input[k] - 'a';	
			v[a]++;
			if (v[a] > max.second) {
				max.first = input[k];
				max.second = v[a];
			}
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		if (v[0] == v[1]) cout << "?" << endl;
		else cout << max.first << endl;
	}

	return 0;
}