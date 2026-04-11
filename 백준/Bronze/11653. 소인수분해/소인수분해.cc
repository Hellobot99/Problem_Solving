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

	int a, b = 2;

	cin >> a;

	while (a != 1 && a >= b)
	{
		while (a % b == 0)
		{
			a /= b;
			cout << b << endl;
		}
		b++;
	}

	return 0;
}