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

	vector<vector<char>> vec(15);
	string s;

	for (int z = 0; z < 5; z++)
	{
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			vec[i].push_back(s[i]);
		}
	}

	for (int z = 0; z < 15; z++)
		for (auto iter = vec[z].begin(); iter != vec[z].end(); iter++)
			cout << *iter;

	return 0;
}