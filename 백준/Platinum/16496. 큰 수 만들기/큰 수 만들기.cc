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

bool cmp(pair<int,string> a, pair<int,string> b) {
    return a.second + b.second > b.second + a.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string a;
    bool zero = true;
    vector<pair<int,string>> arr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a != "0") zero = false;
        arr.push_back(make_pair(a[0] - '0', a));
    }

    sort(arr.begin(), arr.end(),cmp);

    if (zero) cout << "0";
    else 
        for (auto iter = arr.begin(); iter != arr.end(); iter++) cout << iter->second;
    
    return 0;
}