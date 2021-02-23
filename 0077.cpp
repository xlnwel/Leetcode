#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
private:
    void dfs(int n, int k, int i) {
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }
        while (i <= n-k+v.size()+1) {
            v.push_back(i);
            dfs(n, k, ++i);
            v.pop_back();
        }
    }
    vector<vector<int>> ans;
    vector<int> v;
};
