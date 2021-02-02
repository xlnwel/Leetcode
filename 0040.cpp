#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0);
        return ans;
    }
private:
    void helper(const vector<int>candidates, int target, int i) {
        int j;
        while (i < candidates.size() && candidates[i] <= target) {
            v.push_back(candidates[i]);
            if (candidates[i] == target)
                ans.push_back(v);
            else
                helper(candidates, target - candidates[i], i+1);
            v.pop_back();
            j = i;
            while (++j < candidates.size() && candidates[j] == candidates[i]);
            i = j;
        }
    }
    vector<int> v;
    vector<vector<int>> ans;
};