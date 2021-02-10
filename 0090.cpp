#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, v);
        return ans;
    }
private:
    void dfs(const vector<int>& nums, int i, vector<int>& v) {
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }
        int n = 1;
        while (i + 1 != nums.size() && nums[i] == nums[i+1]) {
            ++n;
            ++i;
        }
        dfs(nums, i+1, v);
        for (auto j = 0; j < n; ++j) {
            v.push_back(nums[i]);
            dfs(nums, i+1, v);
        }
        for (auto j = 0; j < n; ++j)
            v.pop_back();
    }
    vector<vector<int>> ans;
};