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

	vector<long long> vec(91);

	vec[0] = 0;
	vec[1] = 1;

	for (int i = 2; i < 91; i++)
	{
		vec[i] = vec[i - 1] + vec[i - 2];
	}

	int a;
	cin >> a;
	cout << vec[a];

	return 0;
}