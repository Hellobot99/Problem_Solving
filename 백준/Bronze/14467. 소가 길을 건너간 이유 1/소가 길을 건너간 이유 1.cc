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

	int a, b, c, result = 0;

	vector<int> vec(101, -1);

	cin >> a;

	for (int i = 0; i < a; i++)
	{
		cin >> b >> c;
		if (vec[b] == -1)
		{
			vec[b] = c;
		}
		else if (vec[b] != c)
		{
			result++;
			vec[b] = c;
		}
	}

	cout << result;

	return 0;
}