#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

long long three(vector<long long>list) {
    long long m = min({ list[3] + list[4] + list[5],list[4] + list[5] + list[2],list[5] + list[1] + list[3],list[5] + list[1] + list[2],list[0] + list[1] + list[2], list[0] + list[3] + list[4], list[0] + list[2] + list[4], list[0] + list[1] + list[3] });
    return 4 * m;
}

long long two(vector<long long>list, long long N) {
    long long m = min({ list[4] + list[5],list[3] + list[5],list[3] + list[4],list[5] + list[2],list[4] + list[2],list[1] + list[5],list[1] + list[3],list[1] + list[2],list[0] + list[4],list[0] + list[3],list[0] + list[1],list[0] + list[2] });
    return 8 * (N - 2) * m + 4 * m;
}

long long one(vector<long long>list, long long N) {
    long long m = min({ list[0],list[1],list[2],list[3],list[4],list[5]});
    return 5 * (N - 2) * (N - 2) * m + 4 * (N - 2) * m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, a;
    vector <long long> list;

    cin >> N;

    for (int i = 0; i < 6; i++) {
        cin >> a;
        list.push_back(a);
    }

    if (N == 1) {
        sort(list.begin(), list.end());
        cout << list[0] + list[1] + list[2] + list[3] + list[4];
    }
    else {
        cout<< one(list, N) + two(list, N) + three(list);
    }

    return 0;
}