#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v(k);
        dfs(v, n, 1, k);
        return ans;
    }
private:
    void dfs(vector<int>& v, int n, int i, int k) {
        if (k == 0) {
            ans.push_back(v);
            return;
        }
        --k;
        while (i <= n - k) {
            v[k] = i;
            dfs(v, n, ++i, k);
        }
    }
    vector<vector<int>> ans;
};