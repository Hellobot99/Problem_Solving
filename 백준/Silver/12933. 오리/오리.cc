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

int interpret(char c);
int solve(string input);
int check(vector<int> vec, int size);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	cout << solve(input);

	return 0;
}

int solve(string input) {
	vector<int> vec;
	int inputSize = input.size(), m;

	for (int i = 0; i < inputSize; i++) {
		m = interpret(input[i]);
		if (vec.empty()) {
			if (m == 1) vec.push_back(1);
			else return -1;
		}
		else {
			auto iter = find(vec.begin(), vec.end(), m - 1);
			if (iter != vec.end())
				(*iter) = ((*iter) + 1) % 5;
			else if (m == 1)
				vec.push_back(1);
			else
				return -1;
		}
	}

	if (check(vec, vec.size()) == 1)
		return vec.size();

	return -1;
}

int interpret(char c) {
	switch (c) {
	case 'q':
		return 1;
	case 'u':
		return 2;
	case 'a':
		return 3;
	case 'c':
		return 4;
	case 'k':
		return 5;
	}

	return -1;
}

int check(vector<int> vec, int size) {
	for (int i = 0; i < size; i++) 
		if (vec[i] != 0) return -1;
			
	return 1;
}