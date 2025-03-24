#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <cmath>
using namespace std;



void print(vector<vector<char>>& arr, int n, int x, int y, bool five) {
    if (n == 1) {
        if (five) 
            return;        
        arr[x][y] = '*';
        return;
    }
    else {
        int a = n / 3;
        if (five) {
            print(arr, a, x, y, true), print(arr, a, x, y + a, true), print(arr, a, x, y + 2 * a, true);
            print(arr, a, x + a, y, true), print(arr, a, x + a, y + a, true), print(arr, a, x + a, y + 2 * a, true);
            print(arr, a, x + 2 * a, y, true), print(arr, a, x + 2 * a, y + a, true), print(arr, a, x + 2 * a, y + 2 * a, true);
            return;
        }        
        print(arr, a, x, y, false), print(arr, a, x, y + a, false), print(arr, a, x, y + 2 * a, false);
        print(arr, a, x + a, y, false), print(arr, a, x + a, y + a, true), print(arr, a, x + a, y + 2 * a, false);
        print(arr, a, x + 2 * a, y, false), print(arr, a, x + 2 * a, y + a, false), print(arr, a, x + 2 * a, y + 2 * a, false);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;
    cin >> input;
    vector<vector<char>> arr(input, vector<char>(input, ' '));
    print(arr, input, 0, 0, false);

    for (int i = 0; i < input; i++) {
        for (int k = 0; k < input; k++) {
            cout << arr[i][k];
        }
        cout << endl;
    }

    return 0;
}