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

typedef struct {
	int h;
	int m;
	int s;
} time_s;

time_s solve(time_s start, time_s end);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	time_s start, end, result;

	scanf("%d:%d:%d", &start.h, &start.m, &start.s);
	scanf("%d:%d:%d", &end.h, &end.m, &end.s);

	result = solve(start, end);

	if (result.h < 10) cout << 0;
	cout << result.h << ":";
	if (result.m < 10) cout << 0;
	cout << result.m << ":";
	if (result.s < 10) cout << 0;
	cout << result.s;

	return 0;
}

time_s solve(time_s start, time_s end) {
	time_s result;

	if (start.h == end.h && start.m == end.m && start.s == end.s) {
		result.h = 24;
		result.m = 0;
		result.s = 0;
		return result;
	}

	end.h += 24;	

	if (end.s < start.s) {
		end.m--;
		end.s += 60;
	}
	if (end.m < start.m) {
		end.h--;
		end.m += 60;
	}

	result.h = end.h - start.h;
	result.m = end.m - start.m;
	result.s = end.s - start.s;

	if (result.h >= 24) result.h -= 24;

	return result;
}