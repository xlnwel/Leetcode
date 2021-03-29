#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        for (auto i: nums) {
            int n = ans.size();
            for (auto k = 0; k != n; ++k) {
                auto v = ans[k];
                v.push_back(i);
                ans.push_back(std::move(v));
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, 0, v);
        return ans;
    }
private:
    void dfs(vector<int>& nums, int i, vector<int>& v) {
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }
        dfs(nums, i+1, v);
        v.push_back(nums[i]);
        dfs(nums, i+1, v);
        v.pop_back();
    }
    vector<vector<int>> ans;
};
