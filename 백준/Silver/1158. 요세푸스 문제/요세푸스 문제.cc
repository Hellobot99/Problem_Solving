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


void solve(int K, queue<int>& queue) {
    int size = queue.size();
    cout << "<";
    for (int i = 0; i < size - 1; i++) {
        for (int k = 0; k < K - 1; k++) {
            queue.push(queue.front());
            queue.pop();
        }
        cout << queue.front() << ", ";
        queue.pop();
    }
    cout << queue.front() << ">";
}


int main() {

    int N, K;
    cin >> N >> K;

    queue<int> queue;

    for (int i = 1; i < N + 1; i++) 
        queue.push(i);
    

    solve(K, queue);

    return 0;
}