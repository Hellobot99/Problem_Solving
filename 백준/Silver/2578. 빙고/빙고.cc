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

int check(vector<vector<int>> vec);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>>p(5, vector<int>(5));
	vector<int>input;
	vector<vector<int>>vec(5, vector<int>(5, 0));
	int a;

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			cin >> p[i][k];
		}
	}

	for (int i = 0; i < 25; i++) {
		cin >> a;
		input.push_back(a);
	}


	for (int i = 0; i < 25; i++)
		for (int k = 0; k < 5; k++)
			for (int j = 0; j < 5; j++)
				if (input[i] == p[k][j]) {
					vec[k][j] = 1;
					if (check(vec)) {
						cout << i + 1;
						return 0;
					}
					break;
				}

	return 0;
}

int check(vector<vector<int>> vec) {
	int c = 0, a = 0;

	for (int i = 0; i < 5; i++) {
		a = 0;
		for (int k = 0; k < 5; k++) {
			if(vec[i][k]) a++;
		}
		if (a == 5) c++;
	}

	for (int i = 0; i < 5; i++) {
		a = 0;
		for (int k = 0; k < 5; k++) {
			if (vec[k][i]) a++;
		}
		if (a == 5) c++;
	}

	a = 0;

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			if (i == k && vec[i][k]) a++;
		}
		if (a == 5) c++;
	}

	a = 0;

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			if (4 - i == k && vec[k][i]) a++;
		}
		if (a == 5) c++;
	}
	
	if (c >= 3) return 1;
	return 0;
}
