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

bool cmp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
    return a.second + b.second > b.second + a.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool use = false;
    int N, K, b, max = -1;
    string a, result = "",c;
    cin >> K >> N;
    vector<pair<pair<int,int>,string>> arr;
    for (int i = 0; i < K; i++) {
        cin >> a;
        if (max < stoi(a)) max = stoi(a);
        arr.push_back(make_pair(make_pair(stoi(a),a[0]), a));
    }
    c = to_string(max);
    sort(arr.begin(), arr.end(),cmp);
    b = 0;

    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        if (iter->second == c && !use) {
            for (int i = 0; i < N - arr.size() + 1; i++) {
                if (iter->second + result > result + iter->second) result = iter->second + result;
                else result = result + iter->second;
            }
            use = true;
            continue;
        }
        if (iter->second + result > result + iter->second) result = iter->second + result;
        else result = result + iter->second;        
    }

    cout << result <<endl;  
    
    return 0;
}