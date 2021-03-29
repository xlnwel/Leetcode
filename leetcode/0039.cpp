#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, v);
        return ans;
    }
private:
    void helper(const vector<int>& candidates, int i, int target, vector<int>& v) {
        while (i < candidates.size() && candidates[i] <= target) {
            v.push_back(candidates[i]);
            if (target == candidates[i]) {
                ans.push_back(v);
            }
            else
                helper(candidates, i, target - candidates[i], v);
            v.pop_back();
            ++i;
        }
    }
    vector<vector<int>> ans;
};