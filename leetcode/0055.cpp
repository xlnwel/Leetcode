#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        for (int i = 0; i < nums.size() && i <= end; ++i) {
            end = max(i + nums[i], end);
        }
        return end >= nums.size() - 1;
    }
};
