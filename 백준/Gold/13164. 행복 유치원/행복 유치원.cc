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

    int N, K, a, result = 0;
    vector<int> arr, aaa;
    priority_queue<pair<int, int>> list;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> a;
        arr.push_back(a);
        if (i) 
            list.push(make_pair(arr[i] - arr[i - 1],i - 1));
    }

    if (K == 1) {
        cout << arr[arr.size() - 1] - arr[0];
        return 0;
    }

    for (int i = 0; i < K - 1;i++) {
        aaa.push_back(list.top().second);
        list.pop();        
    }

    sort(aaa.begin(), aaa.end());

    int before = 0;
    for (auto iter = aaa.begin(); iter != aaa.end(); iter++) {
        result += arr[*iter] - arr[before];
        before = *iter + 1;
    }
    
    result += arr[arr.size() - 1] - arr[before];

    cout << result;

    return 0;
}