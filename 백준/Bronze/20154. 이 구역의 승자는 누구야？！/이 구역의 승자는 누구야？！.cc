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

	string s;
	int result = 0;

	cin >> s;

	vector<int> vec = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};

	for (int i = 0; i < s.size(); i++)
	{
		result += vec[s[i] - 'A'];
	}

	if (result % 2 == 0)
		cout << "You're the winner?";
	else
		cout << "I'm a winner!";

	return 0;
}