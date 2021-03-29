#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        auto matches = [&](int i, int j) {
            return s[i-1] == p[j-1] || p[j-1] == '.';
        };
        vector dp(s.size()+1, vector(p.size()+1, false));
        dp[0][0] = true;
        for (auto i = 2; i <= p.size() && p[i-1] == '*'; i+=2) {
            dp[0][i] = dp[0][i-2];
        }
        for (auto i = 1; i <= s.size(); ++i) {
            for (auto j = 1; j <= p.size(); ++j) {
                if (matches(i, j))
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*') {
                    dp[i][j] = (matches(i, j-1) && dp[i-1][j]) || dp[i][j-2];
                }
            }
        }
        return dp.back().back();
    }
};
