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

    int N, begin, end, current = 0, count = 0;
    vector<pair<int, int>> list;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> begin >> end;
        list.push_back(make_pair(end, begin));
    }

    sort(list.begin(), list.end());

    current = list.begin()->first;
    count++;

    for (auto iter = list.begin(); iter != list.end(); iter++) {
        if (iter == list.begin()) continue;
        if (iter->second >= current) {
            current = iter->first;
            count++;
        }
    }

    cout << count;

    return 0;
}