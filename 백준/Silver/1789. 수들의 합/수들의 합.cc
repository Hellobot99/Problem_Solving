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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long S;

    cin >> S;
    long long a = 1, count = 0, i = 0;

    while (i <= S) {
        i += a;
        a++;
    }

    if (S == 1 || S == 2) cout << 1;
    else cout << a - 2;

    return 0;
}