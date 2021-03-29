#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        for (; i != s.size() && s[i] == ' '; ++i);
        if (s[i] == '+' || s[i] == '-')
            ++i;
        if (i == s.size())
            return false;
        auto has_digit = false;
        auto has_dot = false;
        auto has_e = false;
        int j = s.size();
        while (s[j-1] == ' ')
            --j;
        for (; i != j; ++i) {
            if (isdigit(s[i])) {
                has_digit = true;
                continue;
            }
            if ((s[i] == 'e' || s[i] == 'E') && !has_e && has_digit) {
                if (s[i+1] == '+' || s[i+1] == '-')
                    ++i;
                if (i == j - 1)
                    return false;
                has_e = has_dot = true;
            }
            else if (s[i] == '.' && !has_dot) {
                has_dot = true;
            }
            else
                return false;
        }
        return has_digit;
    }
};