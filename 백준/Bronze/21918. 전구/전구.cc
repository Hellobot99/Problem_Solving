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

	int a, b, c, n, m;

	cin >> n >> m;
	vector<int> v(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int z = 0; z < m; z++) {
		cin >> a >> b >> c;
		switch (a) {
		case 1:
			v[b] = c;
			break;
		case 2:
			for (int i = b; i <= c; i++) {
				if (v[i]) v[i] = 0;
				else v[i] = 1;
			}
			break;
		case 3:
			for (int i = b; i <= c; i++) v[i] = 0;
			break;
		case 4:
			for (int i = b; i <= c; i++) v[i] = 1;
			break;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << v[i] <<  " ";
	}

	return 0;
}