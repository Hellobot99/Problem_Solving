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


void LCS_iter(string a, string b, vector<vector<int>>& P, vector<vector<int>>& R);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A, B;
    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    vector<vector<int>> P(n + 1, vector<int>(m + 1));
    vector<vector<int>> R(n + 1, vector<int>(m + 1));

    LCS_iter(A, B, P, R);

    cout << P[n][m];

    return 0;
}

void LCS_iter(string a, string b, vector<vector<int>> &P, vector<vector<int>>& R)
{
    a = ' ' + a;
    b = ' ' + b;

    int n = a.size()-1;
    int m = b.size()-1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                P[i][j] = P[i - 1][j - 1] + 1;
                R[i][j] = 1;
            }
            else {
                int x = P[i][j - 1];
                int y = P[i - 1][j];
                P[i][j] = max(x,y);
                if (x > y) R[i][j] = 2;
                else R[i][j] = 3;
            }
               
        }
    }
}