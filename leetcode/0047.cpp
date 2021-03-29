#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
private:
    void backtrack(vector<int>& v, int i) {
        if (i == v.size()) {
            ans.push_back(v);
            return;
        }
        set<int> s;
        for (auto j = i; j != v.size(); ++j) {
            if (s.find(v[j]) != s.end())
                continue;
            s.insert(v[j]);
            swap(v[i], v[j]);
            backtrack(v, i+1);
            swap(v[i], v[j]);
        }
    }
    vector<vector<int>> ans;
};

class Solution2 {
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