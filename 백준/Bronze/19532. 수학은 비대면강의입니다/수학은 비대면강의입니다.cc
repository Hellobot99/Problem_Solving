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
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d, e, f, x, y, q;

	cin >> a >> b >> c >> d >> e >> f;

	int det = a * e - b * d;
	x = (c * e - b * f) / det;
	y = (a * f - c * d) / det;

	cout << x << " " << y;

	return 0;
}