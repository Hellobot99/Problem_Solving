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

	int a, b, c, count = 0;

	cin >> a;
	b = a;

	do
	{
		if (a >= 10)
			c = a / 10 + a % 10;
		else
			c = a;

		a = c % 10 + ((a % 10) * 10);

		count++;
	} while (a != b);

	cout << count;

	return 0;
}