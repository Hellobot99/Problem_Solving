#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, i = 0, count = 0, num = 0;
    string a, b;
    cin >> N >> K;
    cin >> a;
    stack<char>s;
   

    for (i = 0; i < N; i++) {
        if (!i) s.push(a[i]);
        else {
            while (!s.empty() && a[i] > s.top() && count != K) {
                s.pop();
                count++;
            }
            s.push(a[i]);
        }
    }

    if (s.empty()) {
        for (int k = 0; k < N; k++) {
            s.push(a[k]);
        }
    }
    else {
        for (; i < N; i++) {
            s.push(a[i]);
        }
    }   

    while (count != K) {
        count++;
        s.pop();
    }

    while (!s.empty()) {
        b.push_back(s.top());
        s.pop();
    }    

    reverse(b.begin(), b.end());

    cout << b;    

    return 0;
}