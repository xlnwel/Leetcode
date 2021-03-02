#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k > m || k > n)
            return 0;
        vector dp(n, vector(k, vector<long long>(m, 0)));
        for (auto n1 = 0; n1 != n; ++n1)
            dp[n1][0][0] = 1;
        for (auto m1 = 0; m1 != m; ++m1) 
            dp[0][0][m1] = 1;
        long long mod = 1e9 + 7;
        for (auto n1 = 1; n1 != n; ++n1) {
            for (auto m1 = 0; m1 != m; ++m1) {
                dp[n1][0][m1] = dp[n1-1][0][m1] * (m1+1);
                assert(dp[n1][0][m1] > 0);
                dp[n1][0][m1] %= mod;
            }
            for (auto k1 = 1; k1 != k; ++k1) {
                if (k1 > n1)
                    break;
                for (auto m1 = k1; m1 < m; ++m1) {
                    dp[n1][k1][m1] = accumulate(
                        dp[n1-1][k1-1].begin(), 
                        dp[n1-1][k1-1].begin()+m1, 
                        dp[n1-1][k1][m1]*(m1+1));
                    assert(dp[n1][k1][m1] > 0);
                    dp[n1][k1][m1] %= mod;
                }
            }
        }
        auto op = [mod](long long x, long long  y) { return (x + y) % mod; };
        return accumulate(dp[n-1][k-1].begin()+k-1, dp[n-1][k-1].end(), 0, op);
    }
};
