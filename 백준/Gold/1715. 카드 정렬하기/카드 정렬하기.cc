#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int insertion(vector<int>&arr) {
    int a = arr[0] + arr[1];
    arr.erase(arr.begin());
    arr.erase(arr.begin());

    arr.push_back(a);
    
    int j, key, size = arr.size();
    key = arr[size - 1];
    for (j = size - 2; j >= 0 && arr[j] > key; j--) {
        arr[j + 1] = arr[j];
    }
    arr[j + 1] = key;
    
    return a;
}

int solve(vector<int>arr, int size) {
    int result = 0;

    for (int i = 0; i < size - 1; i++) 
        result += insertion(arr);
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>arr;
    int N ,a;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    cout << solve(arr, N);

    return 0;
}