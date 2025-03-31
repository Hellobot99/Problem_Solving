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

void solve(stack<pair<int, int>>& s, int N) {
    if (s.size() == 1) {
        cout << 0;
        return;
    }
    vector<int> result(N, 0);
    stack<pair<int, int>> arr;
    arr.push(s.top());
    s.pop();
    while (!s.empty()) {
        while (!arr.empty() && s.top().first > arr.top().first) {
            result[arr.top().second - 1] = s.top().second;
            arr.pop();
        }
        arr.push(s.top());
        s.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}



int main() {

    int N, a;
    cin >> N;
    stack<pair<int,int>> stack;

    for (int i = 0; i < N; i++) {
        cin >> a;
        stack.push(make_pair(a, i + 1));
    }       
    solve(stack, N);

    return 0;
}