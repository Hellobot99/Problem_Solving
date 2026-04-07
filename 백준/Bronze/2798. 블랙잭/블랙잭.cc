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

	int n, m, a, max = 0;
	vector<int> arr;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int c = arr[i] + arr[j] + arr[k];
				if (c <= m && c > max)
					max = c;
			}
		}
	}

	cout << max;

	return 0;
}