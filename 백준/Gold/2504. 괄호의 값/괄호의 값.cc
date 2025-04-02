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

bool error = false;

void ps(stack<pair<int, int>> s) {
    while (!s.empty()) {
        cout << s.top().first << " " << s.top().second << endl;
        s.pop();
    }
    cout << endl;
}

void cal(stack<pair<int,int>>& s, int a) {
    vector<int> arr;
    int result = 0;

    switch (a) {
    case '(':
        s.push(make_pair(a, 0));
        break;
    case '[':
        s.push(make_pair(a, 0));
        break;
    case ')':        
        while (!s.empty() && s.top().first != '(' && s.top().second != 0) {
            result += s.top().first;
            s.pop();
        }
        if (s.empty() || s.top().first != '(') {
            error = true;
            return;
        }
        s.pop();
        if (result == 0) s.push(make_pair(2, 1));
        else s.push(make_pair(result * 2, 1));
        break;
    case ']':
        while (!s.empty() && s.top().first != '[' && s.top().second != 0) {
            result += s.top().first;
            s.pop();
        }
        if (s.empty() || s.top().first != '[') {
            error = true;
            return;
        }
        s.pop();
        if (result == 0) s.push(make_pair(3, 1));
        else s.push(make_pair(result * 3, 1));
        break;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<int,int>> s;
    string input;
    int result = 0;
    cin >> input;
    if (input.size() % 2) {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < input.size(); i++) {
        
        cal(s, input[i]);
        if (error) {
            cout << "0";
            return 0;
        }
        //ps(s);
    }

    if (s.empty()) {
        cout << "0";
        return 0;
    }

    while (!s.empty()) {
        if (s.top().second == 0) {
            cout << "0";
            return 0;
        }
        result += s.top().first;
        s.pop();
    }
    
    cout << result;

    return 0;
}