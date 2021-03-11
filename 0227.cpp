#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> is;
        stack<char> cs;
        int sign = 1;
        for (auto i = 0; i != s.size(); ++i) {
            switch(s[i]) {
            case '+': case '*': case '/':
                cs.push(s[i]);
                break;
            case '-':
                cs.push('+');
                sign = -1;
                break;
            case ' ':
                break;
            default:
                int val = s[i] - '0';
                while (i+1 != s.size() && isdigit(s[i+1])) {
                    val = val * 10 + (s[++i] - '0');
                }
                val *= sign;
                sign = 1;
                if (cs.empty())
                    is.push(val);
                else if (cs.top() == '*') {
                    is.top() *= val;
                    cs.pop();
                }
                else if (cs.top() == '/') {
                    is.top() /= val;
                    cs.pop();
                }
                else
                    is.push(val);
            }
        }
        assert(is.size() == cs.size()+1);
        int x = is.top();
        is.pop();
        while (!is.empty()) {
            x = cs.top() == '+'? is.top() + x: is.top() - x;
            is.pop();
            cs.pop();
        }
        return x;
    }
};