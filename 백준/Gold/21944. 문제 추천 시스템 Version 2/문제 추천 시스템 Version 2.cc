#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 
	
	int T, N, M, P, L, G;
	string s;
	map<int, set<pair<int,int>>> t_map;
	map<int, pair<int,int>> check;
	set<pair<int, int>> t_set;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L >> G;
		t_map[G].insert(make_pair(L, P));
		t_set.insert(make_pair(L, P));
		check[P] = make_pair(L,G);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s[0] == 'a') {
			//add
			cin >> P >> L >> G;
			t_map[G].insert(make_pair(L, P));
			t_set.insert(make_pair(L, P));
			check[P] = make_pair(L, G);
		}
		else if (s == "recommend") {
			//recommend1
			cin >> G >> P;
			if (P == 1) {
				//difficult
				set<pair<int, int>>& temp = t_map[G];
				auto iter = temp.end();
				iter--;
				cout << iter->second << endl;
			}
			else {
				//easy
				set<pair<int, int>>& temp = t_map[G];
				auto iter = temp.begin();
				cout << iter->second << endl;
			}
		}
		else if (s == "recommend2") {
			cin >> P;
			if (P == 1) {
				//difficult
				auto iter = t_set.end();
				iter--;
				cout << iter->second << endl;
			}
			else {
				//easy
				auto iter = t_set.begin();
				cout << iter->second << endl;
			}
		}
		else if (s == "recommend3") {
			cin >> P >> L;
			if (P == -1) {
				//difficult
				auto iter = t_set.lower_bound({ L,0 });

				if (iter == t_set.end() || iter == t_set.begin()) {
					cout << "-1" << endl;
					continue;
				}					

				iter--;
				cout << iter->second << endl;					
			}
			else {
				//easy			
				auto iter = t_set.lower_bound({ L,0 });
				if (iter == t_set.end()) 
					cout << "-1" << endl;				
				else 
					cout << iter->second << endl;				
			}
		}
		else {
			//solved
			cin >> P;

			L = check[P].first;
			G = check[P].second;

			t_map[G].erase(make_pair(L, P));
			t_set.erase(make_pair(L, P));
			check.erase(P);
		}
	}

	return 0;
}