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

    int N, a, result = 0;
    vector<int> A, B;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N; i++) {
        cin >> a;
        B.push_back(a);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    reverse(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];
    }

    cout << result;

    return 0;
}