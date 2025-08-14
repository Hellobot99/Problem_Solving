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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 

	set<pair<int,int>> set;
	
	int T, N, M, P, L;
	string s;
	map<int, int> map;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		set.insert(make_pair(L, P));
		map[P] = L;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s[0] == 'a') {
			//add
			cin >> P >> L;
			set.insert(make_pair(L, P));
			map[P] = L;
		}
		else if (s[0] == 'r') {
			//recommand
			cin >> P;
			if (P == 1) {
				//difficult
				auto iter = set.end();
				iter--;
				cout << iter->second << endl;
			}
			else {
				//easy
				auto iter = set.begin();
				cout << iter->second << endl;
			}
		}
		else {
			//solved
			cin >> P;
			set.erase(make_pair(map[P], P));
			map.erase(P);
		}
	}

	return 0;
}