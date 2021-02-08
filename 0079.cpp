#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (board[i][j] == word[0]) {
                    board[i][j] = 0;
                    if (dfs(board, m, n, i, j, word, 1))
                        return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, int m, int n, int i, int j, const string& word, int k) {
        if (k == word.size())
            return true;
        if (i > 0 && board[i-1][j] == word[k]) {
            board[i-1][j] = 0;
            if (dfs(board, m, n, i-1, j, word, k+1))
                return true;
            board[i-1][j] = word[k];
        }
        if (i+1 < m && board[i+1][j] == word[k]) {
            board[i+1][j] = 0;
            if (dfs(board, m, n, i+1, j, word, k+1))
                return true;
            board[i+1][j] = word[k];
        }
        if (j > 0 && board[i][j-1] == word[k]) {
            board[i][j-1] = 0;
            if (dfs(board, m, n, i, j-1, word, k+1))
                return true;
            board[i][j-1] = word[k];
        }
        if (j+1 < n && board[i][j+1] == word[k]) {
            board[i][j+1] = 0;
            if (dfs(board, m, n, i, j+1, word, k+1))
                return true;
            board[i][j+1] = word[k];
        }
        return false;
    }
};