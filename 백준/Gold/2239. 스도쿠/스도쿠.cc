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

void print_board(vector<vector<int>> board) {
	for (int i = 1; i <= 9; i++) {
		for (int k = 1; k <= 9; k++) {
			cout << board[i][k];
		}
		cout << endl;
	}
}

bool promising(vector<vector<int>>& board, int x, int y) {
	int a = board[x][y];
	for (int i = 1; i <= 9; i++) {
		if (i != y && board[x][i] == a) return false;
		if (i != x && board[i][y] == a) return false;
	}

	for (int i = 3 * ((x - 1) / 3) + 1; i < 3 * ((x - 1) / 3) + 4; i++) {
		for (int k = 3 * ((y - 1) / 3) + 1; k < 3 * ((y - 1) / 3) + 4; k++) {
			if (i != x && k != y && board[i][k] == a) return false;
		}
	}

	return true;
}

void solve(vector<vector<int>> &board, vector<pair<int, int>>& arr, int N, int n, bool &active, int x, int y) {
	if (!active) return;
	
	if (n == 0) {
		if (n == N) {
			print_board(board);
			active = false;
		}
		else {
			x = arr[n].first;
			y = arr[n].second;
			for (int i = 1; i <= 9; i++) {
				board[x][y] = i;
				solve(board, arr, N, n + 1, active, x, y);
				board[x][y] = 0;
			}			
		}
	}	
	else if (promising(board, x, y)) {

		if (n == N) {
			print_board(board);
			active = false;
		}
		else {
			x = arr[n].first;
			y = arr[n].second;
			for (int i = 1; i <= 9; i++) {
				board[x][y] = i;
				solve(board, arr, N, n + 1, active, x, y);
				board[x][y] = 0;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 

	vector<vector<int>> board(10, vector<int>(10, 0));
	vector<pair<int, int>> arr;
	int N = 0;
	bool active = true;
	string input;

	for (int i = 1; i <= 9; i++) {
		cin >> input;
		for (int k = 1; k <= 9; k++) {
			board[i][k] = input[k - 1] - '0';
			if (board[i][k] == 0) {
				arr.push_back(make_pair(i, k));
				N++;
			}
		}
	}

	solve(board, arr, N, 0, active, 0, 0);

	return 0;
}