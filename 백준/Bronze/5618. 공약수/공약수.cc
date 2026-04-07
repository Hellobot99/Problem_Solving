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

int solve(int a, int b)
{
	while (a != 1 && b != 1)
	{
		if (a > b)
		{
			if (a % b == 0)
				return b;
			else
				a %= b;
		}
		else
		{
			if (b % a == 0)
				return a;
			else
				b %= a;
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, max = 0;
	vector<int> arr;
	vector<int> solution;

	cin >> n;

	for (int z = 0; z < n; z++)
	{
		cin >> a;
		arr.push_back(a);
	}

	int c = solve(arr[0], arr[1]);
	if (n == 3)
		c = solve(c, arr[2]);

	for (int i = 1; i <= sqrt(c); i++)
	{
		if (c % i == 0)
		{
			solution.push_back(i);
			if (i != c / i)
				solution.push_back(c / i);
		}
	}

	sort(solution.begin(), solution.end());

	for (auto iter = solution.begin(); iter != solution.end(); iter++)
	{
		cout << *iter << endl;
	}

	return 0;
}