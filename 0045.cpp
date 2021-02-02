#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int n = 0;
        int i = 0;
        int j = 1;
        int m = 0;
        int next_i = 0;
        while (i < nums.size()) {
            m = nums[i];
            for (; j <= i+nums[i]; ++j) {
                if (j >= nums.size()-1)
                    return n+1;
                if (j + nums[j] > m) {
                    next_i = j;
                    m = j + nums[j];
                }
            }
            i = next_i;
            ++n;
        }
        return n;
    }
};
