#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        array dir{
            make_pair(0, 1), make_pair(1, 0),
            make_pair(0, -1), make_pair(-1, 0)
        };
        int i = 0, j = -1;
        int k = 0;
        auto is_valid = [m, n, &matrix](int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] <= 100;
        };
        while (true) {
            if (auto [x, y] = dir[k]; is_valid(i+x, j+y)) {
                while (is_valid(i+x, j+y)) {
                    i += x;
                    j += y;
                    ans.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                }
            }
            else
                break;
            k = (k+1) % 4;
        }
        return ans;
    }
};
