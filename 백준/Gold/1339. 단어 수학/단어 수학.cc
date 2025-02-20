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

    int N, x = 9, result = 0;
    string a;
    cin >> N;

    map<char,int> arr;
    vector<int> list;

    for (int i = 'A'; i <= 'Z'; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> a;
        int p = 1;
        for (int k = a.size()-1; k >= 0; k--) {
            arr[a[k]] += p;
            p *= 10;
        }
    }

    for (int i = 'A'; i <= 'Z'; i++) 
        if (arr[i] != 0) list.push_back(arr[i]);

    sort(list.begin(), list.end());
    reverse(list.begin(), list.end());

    for (auto iter = list.begin(); iter != list.end(); iter++) {
        result += (*iter) * x;
        x--;
    }
    
    cout << result;

    return 0;
}