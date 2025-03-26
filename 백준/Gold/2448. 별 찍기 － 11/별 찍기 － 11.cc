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



void solve(vector<string>& arr, int n, int x) {
    
    if (n == 3) {
        for (int i = 0; i < n - 1; i++)
            arr[x].push_back(' ');
        arr[x].push_back('*');
        for (int i = 0; i < 3; i++)
            arr[x].push_back(' ');


        arr[x +1].push_back(' ');
        arr[x+1].push_back('*');
        arr[x+1].push_back(' ');
        arr[x +1].push_back('*');
        arr[x + 1].push_back(' ');
        arr[x + 1].push_back(' ');
 

        for(int i=0;i<5;i++)
            arr[x+2].push_back('*');
        arr[x + 2].push_back(' ');
        
  
        return;
    }

    int m = n / 2;

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < m; k++) {
            arr[x + i].push_back(' ');
        }
    }
    
    solve(arr, m, x);
    solve(arr, m, x + m);
    solve(arr, m, x + m);

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < m; k++) {
            arr[x + i].push_back(' ');
        }
    }
}

void print_arr(int n, vector<string> arr) {
    for (int i = 0; i < n; i++) {
        for (auto iter = arr[i].begin(); iter != arr[i].end(); iter++) {
            cout << *iter;
        }
        cout << endl;
    }
}

int main() {

    int n;
    cin >> n;
    vector<string> arr(n);

    solve(arr, n, 0);

    print_arr(n, arr);
    return 0;
}