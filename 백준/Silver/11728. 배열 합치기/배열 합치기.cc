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

	int c, n, m;
	vector<int> a;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		a.push_back(c);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> c;
		a.push_back(c);
	}

	sort(a.begin(), a.end());

	for (auto iter = a.begin(); iter != a.end(); iter++)
		cout << (*iter) << " ";

	return 0;
}