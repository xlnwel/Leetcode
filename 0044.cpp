#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        string p2;
        // omits all consecutive '*'s
        for (auto i = 0; i != p.size(); ++i) {
            if (p[i] == '*')
                for (; i+1 < p.size() && p[i+1] == '*'; ++i);
            p2 += p[i];
        }
        p = p2;
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        dp[0][1] = p[0] == '*';
        for (auto i = 1; i != m+1; ++i) {
            for (auto j = 1; j != n+1; ++j) {
                if (p[j-1] == '?' || p[j-1] == s[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*') 
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};

