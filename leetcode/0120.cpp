#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        vector<int> dp(triangle.back().size());
        dp[0] = triangle[0][0];
        for (auto i = 1; i != triangle.size(); ++i) {
            dp[triangle[i].size()-1] = dp[triangle[i].size()-2] + triangle[i].back();
            for (auto j = triangle[i].size()-2; j > 0; --j) {
                dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
