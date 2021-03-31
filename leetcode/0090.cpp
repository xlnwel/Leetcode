#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
private:
    void backtrack(const vector<int>& nums, int i) {
        if (i > nums.size())
            return;
        ans.push_back(v);
        for (auto j = i; j != nums.size(); ++j) {
            if (j != i && nums[j] == nums[j-1]) continue;
            v.push_back(nums[j]);
            backtrack(nums, j+1);
            v.pop_back();
        }

    }
    vector<vector<int>> ans;
    vector<int> v;
};


class Solution2 {
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