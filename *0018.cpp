#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for (auto i = 0; i != nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            for (auto j = i+1; j != nums.size(); ++j) {
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;
                int rest = target - nums[i] - nums[j];
                int m = j+1;
                int n = nums.size() - 1;
                while (m < n) {
                    int tmp = rest - (nums[m] + nums[n]);
                    if (tmp > 0)
                        while (++m < n && nums[m] == nums[m-1]);
                    else if (tmp < 0)
                        while (--n > m && nums[n] == nums[n+1]);
                    else {
                        ans.push_back({nums[i], nums[j], nums[m], nums[n]});
                        while (++m < n && nums[m] == nums[m-1]);
                        while (--n > m && nums[n] == nums[n+1]);
                    }
                }
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, target);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, int k, int target) {
        if (v.size() == 4) {
            if (target == 0)
                ans.push_back(v);
            return;
        }
        for (auto i = k; i != nums.size(); ++i) {
            if (i > k && nums[i] == nums[i-1])
                continue;
            if ((target > 0 && nums[i] > target) || (target < 0 && nums[i] > 0))
                return;
            v.push_back(nums[i]);
            backtrack(nums, i+1, target-nums[i]);
            v.pop_back();
        }
    }
    vector<int> v;
    vector<vector<int>> ans;
};
