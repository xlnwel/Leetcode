#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix): m(matrix) {
        for (auto i = 1; i != matrix.size(); ++i)
            m[i][0] += m[i-1][0];
        for (auto i = 1; i != matrix[0].size(); ++i)
            m[0][i] += m[0][i-1];
        for (auto i = 1; i != matrix.size(); ++i) {
            for (auto j = 1; j != matrix[0].size(); ++j) {
                m[i][j] += m[i-1][j] + m[i][j-1] - m[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
            return m[row2][col2];
        if (row1 == 0)
            return m[row2][col2] - m[row2][col1-1];
        if (col1 == 0)
            return m[row2][col2] - m[row1-1][col2];
        return m[row2][col2] - m[row2][col1-1] - m[row1-1][col2] + m[row1-1][col1-1];
    }
private:
    vector<vector<int>> m;
};
