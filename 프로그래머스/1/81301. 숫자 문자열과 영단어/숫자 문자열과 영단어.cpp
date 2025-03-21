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

int solution(string s) {
    int answer = 0;
    string temp;
    queue<char> q;
    int c = 1;

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        if (*iter >= '0' && *iter <= '9') {
            while (!q.empty()) {
                string buf;
                for (int i = 0; i < 3; i++) {
                    buf.push_back(q.front());
                    q.pop();
                }
                if (buf == "zer") {
                    temp.push_back('0');
                    q.pop();
                }
                else if (buf == "one") {
                    temp.push_back('1');
                }
                else if (buf == "two") {
                    temp.push_back('2');
                }
                else if (buf == "thr") {
                    temp.push_back('3');
                    q.pop(), q.pop();
                }
                else if (buf == "fou") {
                    temp.push_back('4');
                    q.pop();
                }
                else if (buf == "fiv") {
                    temp.push_back('5');
                    q.pop();
                }
                else if (buf == "six") {
                    temp.push_back('6');
                }
                else if (buf == "sev") {
                    temp.push_back('7');
                    q.pop(), q.pop();
                }
                else if (buf == "eig") {
                    temp.push_back('8');
                    q.pop(), q.pop();
                }
                else if (buf == "nin") {
                    temp.push_back('9');
                    q.pop();
                }
            }
            temp.push_back(*iter);
        }
        else {
            q.push(*iter);
        }

    }

    while (!q.empty()) {
        string buf;
        for (int i = 0; i < 3; i++) {
            buf.push_back(q.front());
            q.pop();
        }
        if (buf == "zer") {
            temp.push_back('0');
            q.pop();
        }
        else if (buf == "one") {
            temp.push_back('1');
        }
        else if (buf == "two") {
            temp.push_back('2');
        }
        else if (buf == "thr") {
            temp.push_back('3');
            q.pop(), q.pop();
        }
        else if (buf == "fou") {
            temp.push_back('4');
            q.pop();
        }
        else if (buf == "fiv") {
            temp.push_back('5');
            q.pop();
        }
        else if (buf == "six") {
            temp.push_back('6');
        }
        else if (buf == "sev") {
            temp.push_back('7');
            q.pop(), q.pop();
        }
        else if (buf == "eig") {
            temp.push_back('8');
            q.pop(), q.pop();
        }
        else if (buf == "nin") {
            temp.push_back('9');
            q.pop();
        }
    }

    reverse(temp.begin(), temp.end());

    for (auto iter = temp.begin(); iter != temp.end(); iter++) {
        int d = c * (*iter - '0');
        if (d)
            answer += c * (*iter - '0');
     
        
        c *= 10;
    }

    return answer;
}