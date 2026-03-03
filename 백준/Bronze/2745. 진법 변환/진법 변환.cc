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
	int b, t = 0, ten = 1;

	cin >> input >> b;

	reverse(input.begin(), input.end());

	for (int i = 0; i < input.size(); i++) {
		char c = input[i];
		if (c >= '0' && c <= '9') t += (ten * (c - '0'));
		else t += (ten * (c - 'A' + 10));
		ten *= b;
	}

	cout << t;

	return 0;
}