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

void solve(int M, queue<pair<int, int>> queue, priority_queue<pair<int, int>> pq)
{
    int c = 1;
    while (1) {
        if (queue.front().first >= pq.top().first) {
            if (queue.front().second == M) {
                cout << c << endl;
                return;
            }
            else {
                c++;
                pair<int, int> a = queue.front();
                vector<pair<int, int>> vec;
                queue.pop();
                while (pq.top() != a) {
                    vec.push_back(pq.top());
                    pq.pop();
                }
                pq.pop();
                for (auto iter = vec.begin(); iter != vec.end(); iter++)
                    pq.push(*iter);
            }
        }
        else {
            queue.push(queue.front());
            queue.pop();
        }
    }
}

int main() {

    int T, N, M, a;
    cin >> T;
    for (int i = 0; i < T; i++) {
        queue<pair<int,int>> queue;
        priority_queue<pair<int,int>> pq;
        cin >> N >> M;
        for (int k = 0; k < N; k++) {
            cin >> a;
            queue.push(make_pair(a, k));
            pq.push(make_pair(a, k));
        }

        solve(M, queue, pq);
    }

    return 0;
}