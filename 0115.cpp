#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1));
        for (auto i = 0; i <= m; ++i)
            dp[i][0] = 1;
        for (auto i = 1; i <= m; ++i) {
            for (auto j = 1; j <= min(i, n); ++j) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};