#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = nums[i-1] > 0? nums[i-1] + nums[i]: nums[i];
            ans = max(nums[i], ans);
        }
        return ans;
    }
};
