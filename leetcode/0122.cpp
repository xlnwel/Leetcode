#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int ans = 0;
        for (auto i = 1; i != prices.size(); ++i) {
            ans += max(prices[i] - prices[i-1], 0);
        }
        return ans;
    }
};