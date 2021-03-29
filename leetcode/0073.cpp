#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;
        for (auto i = 0; i != matrix.size(); ++i)
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }
        for (auto i = 0; i != matrix[0].size(); ++i)
            if (matrix[0][i] == 0) {
                row = true;
                break;
            }
        for (auto i = 1; i != matrix.size(); ++i) {
            for (auto j = 1; j != matrix[0].size(); ++j) {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        for (auto i = 1; i != matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (auto j = 0; j != matrix[0].size(); ++j)
                    matrix[i][j] = 0;
            }
        }
        for (auto j = 1; j != matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                for (auto i = 0; i != matrix.size(); ++i)
                    matrix[i][j] = 0;
            }
        }
        if (row)
            for (auto i = 0; i != matrix[0].size(); ++i) {
                matrix[0][i] = 0;
            }
        if (col)
            for (auto i = 0; i != matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
    }
};