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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    string word;
    stack<char> st;
    cin >> T;
    cin.ignore();
    for (int z = 0; z < T; z++) {
        getline(cin, word);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ' ') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << " ";
            }
            else {
                st.push(word[i]);
            }
        }
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }

    return 0;    
}