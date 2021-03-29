#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        signs.push(1);
        int sign = 1;
        int val = 0;
        for (auto i = 0; i != s.size(); ++i) {
            switch(s[i]) {
            case '-':
                sign = -signs.top();
                break;
            case '+':
                sign = signs.top(); 
            case ' ':
                break;
            case '(':
                signs.push(sign);
                break;
            case ')':
                signs.pop();
                break;
            default:
                int x = sign * (s[i] - '0');
                while (i+1 != s.size() && isdigit(s[i+1])) {
                    x = 10 * x + sign * (s[++i] - '0');
                }
                val += x;
            }
        }
        return val;
    }
};