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

    bool possible = true;
    int N, M, a, count = 0, ma = 0;
    vector<int> krain, box;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        ma = max(a, ma);
        krain.push_back(a);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a;
        if (a > ma) possible = false;
        box.push_back(a);
    }
    
    if (!possible) {
        cout << "-1";
        return 0;
    }

    sort(krain.begin(), krain.end());
    reverse(krain.begin(), krain.end());
    sort(box.begin(), box.end());
    reverse(box.begin(), box.end());
    while (!box.empty()) {
        for (auto iter = krain.begin(); iter != krain.end(); iter++) {
            for (auto it = box.begin(); it != box.end(); it++) {
                if (*iter >= *it) {
                    box.erase(it);
                    break;
                }
            }
        }
        count++;
    }


    cout << count;

    return 0;
}