#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int x, y;
        for (auto& s: tokens) {
            if (s == "+") {
                get_xy(stk, x, y);
                stk.push(x+y);
            }
            else if (s == "-") {
                get_xy(stk, x, y);
                stk.push(x - y);
            }
            else if (s == "*") {
                get_xy(stk, x, y);
                stk.push(x * y);
            }
            else if (s == "/") {
                get_xy(stk, x, y);
                stk.push(x / y);
            }
            else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
    void get_xy(stack<int>& stk, int&x, int& y) {
        y = stk.top();
        stk.pop();
        x = stk.top();
        stk.pop();
    }
};