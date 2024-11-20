#include <iostream>
using namespace std;

int main() {
	int n, a[7], t, p, result1=0;
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	cin >> t >> p;
	for (int i = 0; i < 6; i++) {
		if (a[i] % t)
			result1 += (a[i]) / t + 1;
		else
			result1 += (a[i]) / t;
	}
	cout << result1<<"\n";
	cout << n / p << " " << n % p;
	return 0;
}