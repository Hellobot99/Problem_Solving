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

	string input, f, a;

	cin >> input >> f;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= '0' && input[i] <= '9') continue;
		a.push_back(input[i]);
	}

	if (strstr(a.c_str(), f.c_str()) != nullptr) cout << "1";
	else cout << "0";

	return 0;
}