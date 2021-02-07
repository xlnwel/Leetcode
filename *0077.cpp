#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<bool> visited(n, false);
        vector<int> v(k, 0);
        dfs(v, visited, k, 0);
        return ans;
    }
private:
    void dfs(vector<int>& v, vector<bool>& visited, int k, int i) {
        if (k == 0) {
            ans.push_back(v);
            return;
        }
        --k;
        for (; i != visited.size() - k; ++i) {
            if (!visited[i]) {
                v[k] = i+1;
                visited[i] = true;
                dfs(v, visited, k, i+1);
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> ans;
};