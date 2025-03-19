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

int c = 1;

void solve(vector<vector<int>>& arr, int x, int y, int a, int b, int size)
{
    int half = size / 2;
    int mid_x = x + half;
    int mid_y = y + half;
    int where;

    if (size == 2) {        
        for (int i = x; i < x + 2; i++) {
            for (int k = y; k < y + 2; k++) {   
                if (arr[i][k] == 0) arr[i][k] = c;
            }
        }
        c++;
        return;
    }

    if (a < mid_x && b < mid_y) where = 1;
    else if (a < mid_x && b >= mid_y) where = 2;
    else if (a >= mid_x && b < mid_y) where = 3;
    else where = 4;

    if (where != 1) arr[mid_x - 1][mid_y - 1] = c;
    if (where != 2) arr[mid_x - 1][mid_y] = c;
    if (where != 3) arr[mid_x][mid_y - 1] = c;
    if (where != 4) arr[mid_x][mid_y] = c;
    c++;

    switch (where)
    {
    case 1:
        solve(arr, x, y, a, b, size / 2);
        solve(arr, x, mid_y, mid_x - 1, mid_y, size / 2);
        solve(arr, mid_x, y, mid_x, mid_y - 1, size / 2);
        solve(arr, mid_x, mid_y, mid_x, mid_y, size / 2);
        break;
    case 2:
        solve(arr, x, y, mid_x - 1, mid_y - 1, size / 2);
        solve(arr, x, mid_y, a, b, size / 2);
        solve(arr, mid_x, y, mid_x, mid_y - 1, size / 2);
        solve(arr, mid_x, mid_y, mid_x, mid_y, size / 2);
        break;
    case 3:
        solve(arr, x, y, mid_x - 1, mid_y - 1, size / 2);
        solve(arr, x, mid_y, mid_x - 1, mid_y, size / 2);
        solve(arr, mid_x, y, a, b, size / 2);
        solve(arr, mid_x, mid_y, mid_x, mid_y, size / 2);
        break;
    case 4:
        solve(arr, x, y, mid_x - 1, mid_y - 1, size / 2);
        solve(arr, x, mid_y, mid_x - 1, mid_y, size / 2);
        solve(arr, mid_x, y, mid_x, mid_y - 1, size / 2);
        solve(arr, mid_x, mid_y, a, b, size / 2);
        break;

    default:
        break;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, b;
    cin >> N >> b >> a;
    N = pow(2, N);
    
    a = N - a;
    b--;

    vector<vector<int>> arr(N, vector<int>(N, 0));

    arr[a][b] = -1;

    solve(arr, 0, 0, a, b, N);

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (k == N - 1) cout << arr[i][k];
            else cout << arr[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}