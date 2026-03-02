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

	string s, p;
	cin >> s >> p;

	if (strstr(s.c_str(), p.c_str()) != nullptr) cout << "1";
	else cout << "0";

	return 0;
}