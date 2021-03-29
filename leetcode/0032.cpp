#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        vector dp(s.size() + 1, 0);
        for (auto i = 0; i != s.size(); ++i) {
            if (s[i] == '(' || i-1 < 0)
                continue;
            if (s[i-1] == '(')
                dp[i+1] = dp[i-1]+2;
            else if (i-1-dp[i] >= 0 && s[i-1-dp[i]] == '(')
                dp[i+1] = dp[i] + 2 + dp[i-1-dp[i]];
        }
        return *max_element(dp.begin(), dp.end());
    }
};


class Solution2 {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> dp(s.size()+1, 0);
        for (auto i = 2; i < dp.size(); ++i) {
            if (s[i-1] == ')') {
                if (s[i-2] == '(')
                    dp[i] = dp[i-2] + 2;
                else if (i - dp[i-1] - 2 >= 0 && s[i - dp[i-1] - 2] == '(')
                    dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};