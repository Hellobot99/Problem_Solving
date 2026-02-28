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

	bool t = false;
	string input;
	cin >> input;
		
	for (int i = 0; i < input.size(); i++) {
		switch (input[i] - '0') {
		case 0:
			if (t) cout << "000";
			else t = false;
			break;
		case 1:
			if (t) cout << "001";
			else {
				cout << "1";
				t = true;
			}
			break;
		case 2:
			if (t) cout << "010";
			else {
				cout << "10";
				t = true;
			}
			break;
		case 3:
			if (t) cout << "011";
			else {
				cout << "11";
				t = true;
			}
			break;
		case 4:
			cout << "100";
			t = true;
			break;
		case 5:
			cout << "101";
			t = true;
			break;
		case 6:
			cout << "110";
			t = true;
			break;
		case 7:
			cout << "111";
			t = true;
			break;
		}
	}

	if (!t) cout << "0";

	return 0;
}