#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = r * c;
        if (nums.empty() || nums.size() * nums[0].size() != n)
            return nums;
        vector ans(r, vector(c, 0));
        int m = nums[0].size();
        for (auto i = 0; i != n; ++i) {
            ans[i / c][i % c] = nums[i / m][i % m];
        }
        return ans;
    }
};
