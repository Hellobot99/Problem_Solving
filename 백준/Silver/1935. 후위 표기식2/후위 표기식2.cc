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

void solve(string s, vector<int>& arr) {
    stack<double> stack;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            stack.push((double)arr[s[i]-'A']);
        }
        else {
            double a, b;
            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();

            switch (s[i]) {
            case '+':
                stack.push(a + b);
                break;
            case '-':
                stack.push(a - b);
                break;
            case '*':
                stack.push(a * b);
                break;
            case '/':
                stack.push(a / b);
                break;
            }
        }
    }

    printf("%.2lf", stack.top());
}

int main() {

    int N;
    string s;

    cin >> N;
    cin >> s;
    vector<int> arr(N,0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve(s, arr);

    return 0;
}