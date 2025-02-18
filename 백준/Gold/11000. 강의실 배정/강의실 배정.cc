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

    vector<pair<int, int>>arr;
    priority_queue<int, vector<int>, greater<int>> pq;
    int N, begin, end, count = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> begin >> end;
        arr.push_back(make_pair(begin, end));
    }

    sort(arr.begin(), arr.end());

    for (auto iter = arr.begin(); iter != arr.end();iter++) {
        pq.push(iter->second);
        if (pq.top() <= iter->first) pq.pop();        
    }

    cout << pq.size();

    return 0;
}