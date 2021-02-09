#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        vector<int> v(matrix[0].size(), 0);
        int ans = 0;
        for (auto i = 0; i != matrix.size(); ++i) {
            for (auto j = 0; j != matrix[0].size(); ++j) {
                v[j] = matrix[i][j] == '1'? ++v[j]: 0;
            }
            ans = max(ans, maxArea(v));
        }
        return ans;
    }
private:
    int maxArea(vector<int>& v) {
        stack<int> s;
        vector<int> l(v.size()), r(v.size(), v.size());
        for (auto i = 0; i != v.size(); ++i) {
            while (!s.empty() && v[s.top()] > v[i]) {
                r[s.top()] = i;
                s.pop();
            }
            l[i] = s.empty()? 0: s.top() + 1;
            s.push(i);
        }
        int ans = 0;
        for (auto i = 0; i != v.size(); ++i) {
            ans = max(ans, v[i] * (r[i] - l[i]));
        }
        return ans;
    }
};