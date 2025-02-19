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

    priority_queue<int>pq;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    int N, a, first, second, count = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a > 0) pq.push(a);
        else pqmin.push(a);
    }

    while (pq.size() >= 2) {
        first = pq.top();
        pq.pop();
        second = pq.top();        

        if (first * second > first + second) {
            count += first * second;
            pq.pop();
        }
        else {
            count += first;
        }
    }

    while (pqmin.size() >= 2) {
        first = pqmin.top();
        pqmin.pop();
        second = pqmin.top();       

        if (first * second > first + second) {
            count += first * second;
            pqmin.pop();
        }
        else {
            count += first;
        }
    }

    if (!pqmin.empty()) count += pqmin.top();
    if (!pq.empty()) count += pq.top();

    cout << count;          

    return 0;
}