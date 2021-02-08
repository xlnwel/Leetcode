#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 3)
            return true;
        int n = 0;
        if (nums[0] > nums[1])
            ++n;
        for (int i = 2; i != nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {
                if (nums[i-2] > nums[i]) {
                    nums[i] = nums[i-1];
                }
                ++n;
            }
            if (n > 1)
                return false;
        }
        return true;
    }
};