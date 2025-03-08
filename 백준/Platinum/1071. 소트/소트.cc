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

    bool change = false;
    int N, a, b = 0;
    vector<int> arr, result;
    priority_queue <int, vector<int>, greater<int> > pq;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        pq.push(a);
    }

    a = pq.top();
    result.push_back(a);
    pq.pop();
    
    while (!pq.empty()) {
        while (pq.top() == a + 1) {
            arr.push_back(pq.top());
            pq.pop();
            if (pq.empty()) break;
        }

        if (pq.empty()) {
            for (auto iter = arr.begin(); iter != arr.end(); iter++) {
                result.insert(result.begin() + b, *iter);
            }
            arr.clear();
        }       
        else {
            result.push_back(pq.top());
            if (a != pq.top()) b = result.size() - 1;
            a = pq.top();
            pq.pop();
        }  

        for (auto iter = arr.begin(); iter != arr.end(); iter++) {
            pq.push(*iter);
        }
        arr.clear();
    }

    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }
    
    return 0;
}