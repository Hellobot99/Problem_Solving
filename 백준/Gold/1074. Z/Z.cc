#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <cmath>
using namespace std;

int count1 = 0;

void solve(int N, int r, int c, int x, int y) {
	if (N == 0) {
		if (r == y && c == x)
			cout << count1;
		return;
	}

	int a = pow(2, N - 1);

	int mid_x = x + a;
	int mid_y = y + a;

	if (mid_x > c && mid_y > r) {
		solve(N - 1, r, c, x, y);
		return;
	}
	else {
		count1 += a * a;
	}

	if (mid_x <= c && mid_y > r) {
		solve(N - 1, r, c, mid_x, y);
		return;
	}
	else {
		count1 += a * a;
	}

	if (mid_x > c && mid_y <= r) {
		solve(N - 1, r, c, x, mid_y);
		return;
	}
	else {
		count1 += a * a;
	}

	if (mid_x <= c && mid_y <= r) {
		solve(N - 1, r, c, mid_x, mid_y);
		return;
	}
	else {
		count1 += a * a;
	}
}

int main() {

	int N, r, c;
	cin >> N >> r >> c;

	solve(N, r, c, 0, 0);

	return 0;
}