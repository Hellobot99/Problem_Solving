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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m = 0, n, u = 0, d = 0, recent = INT_MIN;
	pair<int, int> a, b;

	cin >> m;

	a = {m, 0};
	b = {m, 0};

	for (int i = 0; i < 14; i++)
	{
		cin >> n;

		a.second += a.first / n;
		a.first %= n;

		if (i == 0)
		{
			recent = n;
			continue;
		}

		if (recent < n)
		{
			u++;
			d = 0;
		}
		else if (recent == n)
		{
			u = 0;
			d = 0;
		}
		else
		{
			d++;
			u = 0;
		}

		if (u >= 3)
		{
			b.first += b.second * n;
			b.second = 0;
		}
		else if (d >= 3)
		{
			b.second += b.first / n;
			b.first %= n;
		}
	}

	if (a.first + a.second * n > b.first + b.second * n)
		cout << "BNP";
	else if (a.first + a.second * n < b.first + b.second * n)
		cout << "TIMING";
	else
		cout << "SAMESAME";

	return 0;
}