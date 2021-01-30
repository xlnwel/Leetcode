#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long ans = 0;
        for (; i != s.size() && s[i] == ' '; ++i);
        if (s[i] == '+' || s[i] == '-') {
            sign = s[i] == '+'? 1: -1;
            ++i;
        }
        auto max = sign > 0? static_cast<long long>(pow(2, 31)-1): static_cast<long long>(pow(2, 31));
        for (; i != s.size() && isdigit(s[i]); ++i) {
            ans *= 10;
            ans += s[i] - '0';
            if (ans > max)
                return sign * max;
        }
        ans *= sign;

        return ans;
    }
};