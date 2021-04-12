#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int y = 0;
        for (auto x: nums) {
            if (y < 0)
                y = 0;
            y += x;
            ans = max(ans, y);
        }
        return ans;
    }
};