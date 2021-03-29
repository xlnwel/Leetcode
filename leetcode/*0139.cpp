#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set dict(wordDict.begin(), wordDict.end());
        vector dp(s.size()+1, false);
        dp[0] = true;
        for (auto i = 1; i <= s.size(); ++i) {
            for (auto j = 0; j != i && !dp[i]; ++j) {
                dp[i] = dp[j] && dict.count(s.substr(j, i-j));
            }
        }
        return dp[s.size()];
    }
};