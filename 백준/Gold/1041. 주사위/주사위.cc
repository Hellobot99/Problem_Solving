#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

long long three(vector<long long>list) {
    int min = list[0] + list[1] + list[2];
    if (min > list[0] + list[3] + list[4]) min = list[0] + list[3] + list[4];
    if (min > list[0] + list[2] + list[4]) min = list[0] + list[4] + list[2];
    if (min > list[0] + list[1] + list[3]) min = list[0] + list[1] + list[3];
    if (min > list[5] + list[1] + list[2]) min = list[5] + list[1] + list[2];
    if (min > list[5] + list[1] + list[3]) min = list[5] + list[1] + list[3];
    if (min > list[4] + list[5] + list[2]) min = list[5] + list[4] + list[2];
    if (min > list[3] + list[4] + list[5]) min = list[3] + list[4] + list[5];
    long long q = 4 * (long long)min;
    return q;
}

long long two(vector<long long>list, long long N) {
    int min = list[0] + list[1];
    if (min > list[0] + list[2]) min = list[0] + list[2];
    if (min > list[0] + list[3]) min = list[0] + list[3];
    if (min > list[0] + list[4]) min = list[0] + list[4];
    if (min > list[1] + list[2]) min = list[1] + list[2];
    if (min > list[1] + list[3]) min = list[1] + list[3];
    if (min > list[1] + list[5]) min = list[1] + list[5];
    if (min > list[4] + list[2]) min = list[4] + list[2];
    if (min > list[5] + list[2]) min = list[5] + list[2];
    if (min > list[3] + list[4]) min = list[3] + list[4];
    if (min > list[3] + list[5]) min = list[3] + list[5];
    if (min > list[4] + list[5]) min = list[4] + list[5];

    long long q =  8 * (N - 2) * min + 4 * min;
    return q;
}

long long one(vector<long long>list, long long N) {
    long long min = list[0];
    if (min > list[1]) min = list[1];
    if (min > list[2]) min = list[2];
    if (min > list[3]) min = list[3];
    if (min > list[4]) min = list[4];
    if (min > list[5]) min = list[5];

    long long q = 5 * (N - 2) * (N - 2) * min + 4 * (N - 2) * min;
    return q;
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