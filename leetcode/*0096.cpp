#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1)
            return 1;
        vector dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        for (auto i = 2; i <= n; ++i) {
            for (auto j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};