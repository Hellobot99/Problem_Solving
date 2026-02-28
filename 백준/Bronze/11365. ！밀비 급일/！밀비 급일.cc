#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input, output;
	getline(cin, input);

	while (input != "END") {
		reverse(input.begin(), input.end());
		cout << input << endl;
		getline(cin,input);
	}

	return 0;
}