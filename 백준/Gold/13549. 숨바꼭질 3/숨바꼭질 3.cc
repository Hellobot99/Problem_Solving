#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int solve(bool visited[], int n, int k) {
    queue<pair<int, int>> q;
    int count = 0;
    q.push({ n, 0 });
    visited[n] = true;
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (current == k) {
            return steps;
        }

        if (current * 2 < 100001 && !visited[current * 2]) {
            visited[current * 2] = true;
            q.push({ current * 2, steps});
        }
        if (current - 1 >= 0 && !visited[current - 1]) {
            visited[current - 1] = true;
            q.push({ current - 1, steps + 1 });
        }
        if (current + 1 < 100001 && !visited[current + 1]) {
            visited[current + 1] = true;
            q.push({ current + 1, steps + 1 });
        }
    }
    return -1;
}

int main() {

    bool* visited = new bool[100001];
    for (int i = 0; i < 100001; i++) {
        visited[i] = false;
    }

    int n, k;
    cin >> n >> k;

    cout << solve(visited, n, k);

    return 0;
}