#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int row = 1; row != matrix.size(); ++row) {
            for (int i = 1; i != matrix[row].size(); ++i)
                if (matrix[row][i] != matrix[row-1][i-1])
                    return false;
        }
        return true;
    }
};
