#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums.begin(), nums.end());
        return ans;
    }
private:
    void helper(vector<int>::iterator beg, vector<int>::iterator end) {
        if (beg == end) {
            ans.push_back(v);
            return;
        }
        set<int> visited;
        for (auto itr = beg; itr != end; ++itr) {
            if (visited.count(*itr))
                continue;
            visited.insert(*itr);
            swap(*beg, *itr);
            v.push_back(*beg);
            helper(beg+1, end);
            v.pop_back();
            swap(*beg, *itr);
        }
    }
    vector<int> v;
    vector<vector<int>> ans;
};