#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        auto matches = [&](int i, int j) {
            if (i == 0)
                return false;
            return s[i-1] == p[j-1] || p[j-1] == '.';
        };
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for (auto i = 0; i <= m; ++i) {
            for (auto j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];
                    if (matches(i, j-1))
                        dp[i][j] |= dp[i-1][j];
                }
                else {
                    if (matches(i, j))
                        dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};