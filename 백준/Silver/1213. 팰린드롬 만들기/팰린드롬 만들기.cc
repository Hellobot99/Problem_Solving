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

    char b;
    string first, second, arr;
    bool qq = false;
    
    cin >> arr;

    if (arr.size() == 1) {
        cout << arr;
        return 0;
    }

    sort(arr.begin(),arr.end());

    int index = 0;
    while (arr.size() - index > 1) {
        if (arr[index] == arr[index + 1]) {
            first.push_back(arr[index]);
            second.push_back(arr[index]);
            index += 2;
        }
        else {
            if (qq) {
                cout<< "I'm Sorry Hansoo";
                return 0;
            }
            b = arr[index++];
            qq = true;
        }
    }

    if (arr.size() == index + 1) {
        if (qq) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
        else {
            b = arr[index];
            qq = true;
        }
    }

    reverse(second.begin(), second.end());

    if (qq) first.push_back(b);

    for (auto iter = second.begin(); iter != second.end(); iter++) {
        first.push_back(*iter);
    }

    cout << first << endl;

    return 0;
}