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

void solve(int a, int b)
{
	int c = 2, r = 1;
	while (a >= c && b >= c)
	{
		if (a % c == 0 && b % c == 0)
			r = c;
		c++;
	}

	cout << r << endl
		 << (a * b) / r << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, t;

	cin >> a >> b;
	solve(a, b);

	return 0;
}