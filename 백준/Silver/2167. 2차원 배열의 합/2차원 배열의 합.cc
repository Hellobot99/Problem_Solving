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

void solve(vector<vector<int>> vec, int a, int b, int c, int d)
{
	int result = 0;
	for (int i = a; i <= c; i++)
	{
		for (int k = b; k <= d; k++)
		{
			result += vec[i][k];
			// cout << vec[i][k] << endl;
		}
	}

	cout << result << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b, c, d, e;

	cin >> n >> m;

	vector<vector<int>> vec(n + 2, vector<int>(m + 2, 0));

	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= m; k++)
			cin >> vec[i][k];

	cin >> e;

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c >> d;
		int result = 0;
		for (int i = a; i <= c; i++)
		{
			for (int k = b; k <= d; k++)
			{
				result += vec[i][k];
				// cout << vec[i][k] << endl;
			}
		}
		cout << result << "\n";
	}

	return 0;
}