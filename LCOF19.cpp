#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        auto match = [&s, &p](int i, int j) {
            return p[j-1] == '.' || s[i-1] == p[j-1];
        };
        vector dp(s.size()+1, vector(p.size()+1, false));
        dp[0][0] = true;
        for (auto i = 2; i <= p.size(); ++i) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        for (auto i = 1; i <= s.size(); ++i) {
            for (auto j = 1; j <= p.size(); ++j) {
                if (match(i, j))
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*') {
                    dp[i][j] = (match(i, j-1) && dp[i-1][j]) || dp[i][j-2];
                }
                cout << i << j << " " << dp[i][j] << '\n';
            }
        }
        return dp.back().back();
    }
};