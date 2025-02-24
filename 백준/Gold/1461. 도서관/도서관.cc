#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, result = 0, max = 0;
    vector<int> plus, minus;
    bool b = true;

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        cin >> a;
        if (a > 0) {
            plus.push_back(a);
            if (max < a) max = a, b = true;
        }
        else {
            minus.push_back(a);
            if (max < -a) max = -a, b = false;
        }
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    reverse(plus.begin(), plus.end());

    int index = 0;
    while (plus.size() - index > N - 1) {
        if (index == 0 && b == true) {
            result += plus[index];
            index += N;
        }
        else {
            result += plus[index] * 2;
            index += N;
        }
    }

    if (plus.size() - index != 0)
        result += plus[index] * 2;
    if (plus.size() - index != 0 && max == plus[index])
        result -= plus[index];

    index = 0;
    while (minus.size() - index > N - 1) {
        if (index == 0 && b == false) {
            result -= minus[index];
            index += N;
        }
        else {
            result -= minus[index] * 2;
            index += N;
        }
    }

    if (minus.size() - index != 0)
        result -= minus[index] * 2;
    if (minus.size() - index != 0 && max == -minus[index])
        result += minus[index];

    cout << result;

    return 0;
}