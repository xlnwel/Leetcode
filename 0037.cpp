#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<bitset<9>>(9, bitset<9>());
        col = vector<bitset<9>>(9, bitset<9>());
        cell = vector<bitset<9>>(9, bitset<9>());

        int n = 0;
        for (auto i = 0; i != 9; ++i) {
            for (auto j = 0; j != 9; ++j) {
                if (board[i][j] == '.') 
                    ++n;
                else {
                    auto n = board[i][j] - '1';
                    row[i].set(n);
                    col[j].set(n);
                    cell[cell_idx(i, j)].set(n);
                }
            }
        }
        dfs(board, n);
    }
private:
    bool dfs(vector<vector<char>>& board, int n) {
        if (n == 0)
            return true;
        auto [i, j] = get_next(board);
        auto choices = get_choices(i, j);
        for (auto k = 0; k != 9; ++k) {
            if (choices[k]) {
                board[i][j] = k + '1';
                flip(i, j, k);
                if (dfs(board, n - 1))
                    return true;
                flip(i, j, k);
            }
        }
        board[i][j] = '.';
        return false;
    }
    pair<int, int> get_next(vector<vector<char>>& board) {
        pair<int, int> ans;
        int n = 10;
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                if (board[i][j] == '.') {
                    auto k = get_choices(i, j).count();
                    if (k < n) {
                        ans = make_pair(i, j);
                        n = k;
                    }
                }
            }
        }
        return ans;
    }
    void flip(int i, int j, int k) {
        row[i][k].flip();
        col[j][k].flip();
        cell[cell_idx(i, j)][k].flip();
    }
    bitset<9> get_choices(int i, int j) {
        return ~(row[i] | col[j] | cell[cell_idx(i, j)]); 
    }
    int cell_idx(int i, int j) { return i / 3 * 3 + j / 3; }
    vector<bitset<9>> row;
    vector<bitset<9>> col;
    vector<bitset<9>> cell;
};