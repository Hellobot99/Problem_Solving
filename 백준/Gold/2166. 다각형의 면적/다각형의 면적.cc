#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    
    int n, a, b;
    double sum = 0;
    double result;
    cin >> n;
    vector<pair<double, double>>list;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        list.push_back(make_pair(a, b));
    }

    for (int i = 1; i < n-1;i++) {
        sum += ((list[i].first - list[0].first) * (list[i + 1].second - list[0].second) - (list[i + 1].first - list[0].first) * (list[i].second - list[0].second));
    }

    
    if (sum > 0) {
        result = round(sum * 5) / 10;
    }
    else if (sum == 0)
        result = 0.0;
    else
        result = round(-sum * 5) / 10;

    cout << fixed;
    cout.precision(1);
    cout << result;  
    

    return 0;
}