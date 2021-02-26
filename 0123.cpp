#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> dp(prices.size());
        int min_val = prices.front(); 
        int max_val = prices.back();
        int x;
        for (auto i = 1; i != prices.size(); ++i) {
            if ((x = prices[i] - min_val) < 0)
                min_val = prices[i];
            dp[i] = max(dp[i-1], x);
        }
        int ans = dp.back();
        for (auto i = prices.size() - 2; i > 0; --i) {
            if ((x = max_val - prices[i]) < 0)
                max_val = prices[i];
            ans = max(ans, x + dp[i]);
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<pair<int, int>> dp(prices.size(), {0, 0});   // first is the maximum one-time profit up to i, the next is the maximum sum profit obtained up to i
        dp[1].first = max(0, prices[1] - prices[0]);
        dp[1].second = dp[1].first;
        int x;
        int min_i = prices[0] > prices[1];
        for (auto i = 2; i < prices.size(); ++i) {
            dp[i] = dp[i-1];
            if (prices[i] <= prices[min_i])
                min_i = i; 
            for (auto j = i-1; j >= min_i; --j) {
                x = prices[i] - prices[j];
                dp[i].second = max(j > 0?x + dp[j-1].first: x, dp[i].second);
                dp[i].first = max(x, dp[i].first);
            }
        }
        return dp.back().second;
    }
};
