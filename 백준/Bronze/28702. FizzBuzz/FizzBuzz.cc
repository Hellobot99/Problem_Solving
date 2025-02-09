#include <iostream>
#include <string>
using namespace std;

void print(int a) {
    if (a % 3 == 0 && a % 5 == 0) {
        cout << "FizzBuzz";
    }
    else if (a % 3 == 0) {
        cout << "Fizz";
    }
    else if (a % 5 == 0) {
        cout << "Buzz";
    }
    else {
        cout << a;
    }
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int d;
    if (a == "Fizz" || a == "Buzz" || a == "FizzBuzz") {
        if (b == "Fizz" || b == "Buzz" || b == "FizzBuzz") {
            d = stoi(c) + 1;
        }
        else {
            d = stoi(b) + 2;
        }

    }
    else {
        d = stoi(a) + 3;
    }
    print(d);

    return 0;
}