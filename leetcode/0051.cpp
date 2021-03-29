#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2*n-1, false); // there are 2*n-1 diagonals
        diag2 = vector<bool>(2*n-1, false);
        vector<string> m(n, string(n, '.'));
        helper(m, 0, n);
        return ans;
    }
private:
    void helper(vector<string>& m, int row, int n) {
        if (row == n) {
            ans.push_back(m);
            return;
        }
        int a = n - 1 - row;
        int b = n - row + n - 1;
        for (auto i = 0; i != n; ++i) {
            if (col[i] || diag1[i+a] || diag2[b-i])
                continue;
            m[row][i] = 'Q';
            flip(i, a, b);
            helper(m, row+1, n);
            m[row][i] = '.';
            flip(i, a, b);
        }
    }
    void flip(int i, int a, int b) {
        col[i] = col[i] ^ 1;
        diag1[i+a] = diag1[i+a] ^ 1;
        diag2[b-i] = diag2[b-i] ^ 1;
    }
    vector<vector<string>> ans;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
};