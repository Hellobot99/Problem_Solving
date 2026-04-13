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

	int a, b = 0, two = 0, five = 0;
	cin >> a;

	if (a % 2 == 0)
	{
		while (b + 10 <= a)
		{
			five += 2;
			b += 10;
		}
		while (b + 2 <= a)
		{
			two += 1;
			b += 2;
		}
	}
	else
	{
		if (b + 5 <= a)
		{
			five += 1;
			b += 5;
		}
		while (b + 10 <= a)
		{
			five += 2;
			b += 10;
		}
		while (b + 2 <= a)
		{
			two += 1;
			b += 2;
		}
	}

	if (b != a)
	{
		cout << "-1";
	}
	else
		cout << five + two;

	return 0;
}