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
	int hour;
	int min;
	int second;
}time_s;

int c = 0;

void print_time(time_s s) {
	cout << s.hour << " : " << s.min << " : " << s.second << " " << c << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	time_s s, e;

	cin >> n >> k;
	
	s.hour = 0;
	s.min = 0;
	s.second = 0;

	e.hour = n;
	e.min = 0;
	e.second = 0;

	while (s.hour < n + 1) {
		if (s.hour / 10 == k) {
			//print_time(s);
			if (s.hour + 10 >= n + 1) {
				c += (3600 * ((n + 1) % 10));
				break;
			}
			else {
				s.hour += 10;
				c += 36000;
				continue;
			}

			continue;
		}
		else if (s.hour % 10 == k) {
			//print_time(s);
			s.hour++;
			c += 3600;
			
			continue;
		}
		else if (s.min / 10 == k) {
			//print_time(s);
			s.min += 10;
			c += 600;
			
			if (s.min >= 60) {
				s.min %= 60;
				s.hour++;
			}
			continue;
		}
		else if (s.min % 10 == k) {
			//print_time(s);
			s.min++;
			c += 60;

			if (s.min >= 60) {
				s.min %= 60;
				s.hour++;
			}
			continue;
		}
		else if (s.second / 10 == k) {
			//print_time(s);
			s.second += 10;
			c += 10;

			if (s.second >= 60) {
				s.second %= 60;
				s.min++;
			}
			if (s.min >= 60) {
				s.min %= 60;
				s.hour++;
			}
			continue;
		}
		else if (s.second % 10 == k) {
			s.second++;
			c++;
			if (s.second >= 60) {
				s.second %= 60;
				s.min++;
			}
			if (s.min >= 60) {
				s.min %= 60;
				s.hour++;
			}
			continue;
		}
		else {
			s.second++;
			if (s.second >= 60) {
				s.second %= 60;
				s.min++;
			}
			if (s.min >= 60) {
				s.min %= 60;
				s.hour++;
			}
		}
	}

	cout << c;

	return 0;
}