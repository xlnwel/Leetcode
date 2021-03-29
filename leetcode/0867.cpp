#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        vector ans(n, vector(m, 0));
        for (auto i = 0; i != total; ++i) {
            ans[i % n][i / n] = matrix[i / n][i % n];
        }
        return ans;
    }
};
