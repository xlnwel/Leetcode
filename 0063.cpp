#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (auto i = 0; i != m; ++i)
            obstacleGrid[i][0] = !obstacleGrid[i][0];
        for (auto i = 1; i != n; ++i)
            obstacleGrid[0][i] = !obstacleGrid[0][i];
        for (auto i = 1; i != m; ++i) {
            for (auto j = 1; j != n; ++j) {
                if (obstacleGrid[i][j])
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};
