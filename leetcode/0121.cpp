#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int ans = 0;
        int min_val = prices[0];
        for (auto x: prices) {
            ans = max(ans, x - min_val);
            min_val = min(x, min_val);
        }
        return ans;
    }
};