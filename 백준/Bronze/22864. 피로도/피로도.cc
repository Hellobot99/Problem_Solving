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

	int a, b, c, m, p = 0, h = 0, w = 0;
	cin >> a >> b >> c >> m;

	if (a > m) {
		cout << 0;
		return 0;
	}

	while (p <= m && h < 24) {
		if (p + a > m) {
			h++;
			p -= c;
			//cout << p << " " << h << " " << w << endl;
		}
		else {
			h++;
			p += a;
			w += b;
			//cout << p << " " << h << " " << w << endl;
		}
		
		if (p < 0) p = 0;
	}

	cout << w;

	return 0;
}