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

int promising(vector<vector<int>> board, int x, int y, int size) {

	int ox = x, oy = y;
	if (board[x][y] == 0) return 1;
	x++;
	y++;
	while (x < size && y < size && x >= 0 && y >= 0) {
		if (board[x][y] == 1) return 0;
		else {
			x++;
			y++;
		}
	}
	x = ox + 1;
	y = oy - 1;
	while (x < size && y < size && x >= 0 && y >= 0) {
		if (board[x][y] == 1) return 0;
		else {
			x++;
			y--;
		}
	}
	x = ox - 1;
	y = oy + 1;
	while (x < size && y < size && x >= 0 && y >= 0) {
		if (board[x][y] == 1) return 0;
		else {
			x--;
			y++;
		}
	}
	x = ox - 1;
	y = oy - 1;
	while (x < size && y < size && x >= 0 && y >= 0) {
		if (board[x][y] == 1) return 0;
		else {
			x--;
			y--;
		}
	}
	return 1;
}

void print_arr(vector<vector<int>> board) {
	int n = board.size() - 1;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++)
			cout << board[i][k] << " ";
		cout << endl;
	}
}

void solve(vector<pair<int, int>> one, vector<vector<int>>& board, int index, int size, int& result, int temp, int one_size) {
	if (index == 0) {
		solve(one, board, index + 1, size, result, temp, one_size);
		board[one[0].first][one[0].second] = 1;
		solve(one, board, index + 1, size, result, temp + 1, one_size);
		board[one[0].first][one[0].second] = 0;
	}
	else {
		int x = one[index - 1].first;
		int y = one[index - 1].second;

		if (promising(board, x, y, size)) {
			if (index == one_size) {
				if (result < temp) {
					result = temp;
				}
			}
			else {
				solve(one, board, index + 1, size, result, temp, one_size);
				board[one[index].first][one[index].second] = 1;
				solve(one, board, index + 1, size, result, temp + 1, one_size);
				board[one[index].first][one[index].second] = 0;
			}
		}
	}
}



int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, result = 0, a, w = 0, b = 0, t = 0;
	cin >> N;
	vector<pair<int, int>> black, white;
	vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));

	if (N == 1) {
		cin >> a;
		cout << a;
		return 0;
	}

	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++) {
			cin >> a;
			if (a == 1 && (i + k) % 2 == 0) {
				black.push_back(make_pair(i, k));
				b++;
			}
			else if (a == 1) {
				white.push_back(make_pair(i, k));
				w++;
			}
		}

	if (w != 0) {
		solve(white, board, 0, N, result, 0, w);
	}

	if (b != 0) {
		solve(black, board, 0, N, t, 0, b);
		result += t;
	}

	cout << result;


	return 0;
}