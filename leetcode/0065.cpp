#include <string>

using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        int i = s[0] == '+' || s[0] == '-';
        for (; i != s.size() && isdigit(s[i]); ++i);
        if (i == s.size())
            return true;
        if (s[i] == '.') {
            if ((i-1 < 0 || !isdigit(s[i-1])) && (i+1 == s.size() || !isdigit(s[i+1])))
                return false;
            for (++i; i != s.size() && isdigit(s[i]); ++i);
        }
        if (i == s.size())
            return true;
        if (s[i] == 'e' or s[i] == 'E') {
            if (i-1 < 0 || (!isdigit(s[i-1]) && s[i-1] != '.'))
                return false;
            ++i;
            if (s[i] == '+' || s[i] == '-')
                ++i;
            if (i == s.size() || !isdigit(s[i]))
                return false;
            for (; i != s.size() && isdigit(s[i]); ++i);
        }
        if (i == s.size())
            return true;
        return false;
    }
};