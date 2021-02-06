#include <vector>

using namespace std;


class Solution {
public:
    int totalNQueens(int n) {
        ans = 0;
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2*n-1, false);
        diag2 = vector<bool>(2*n-1, false);
        helper(0, n);
        return ans;
    }
private:
    void helper(int row, int n) {
        if (row == n) {
            ++ans;
            return;
        }
        int a = n - 1 - row;
        for (int i = 0; i != n; ++i) {
            if (col[i] || diag1[i+a] || diag2[row+i])
                continue;
            flip(i, a, row);
            helper(row+1, n);
            flip(i, a, row);
        }
    }
    void flip(int i, int a, int b) {
        col[i] = col[i] ^ 1;
        diag1[i+a] = diag1[i+a] ^ 1;
        diag2[b+i] = diag2[b+i] ^ 1;
    }
    int ans;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
};