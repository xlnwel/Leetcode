#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        vector<int> dp(s.size(), 1);
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2')
                    dp[i] = i > 1? dp[i-2]: 1;
                else
                    dp[i] = 0;
                continue;
            }
            dp[i] = dp[i-1];
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) {
                dp[i] += i > 1? dp[i-2]: 1;
            }
        }
        return dp.back();
    }
};
