#include <utility>
#include <vector>
#include <string>
#include <array>

using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector visited(board.size(), vector(board[0].size(), false));

        dirs = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
        for (auto i = 0; i != board.size(); ++i) {
            for (auto j = 0; j != board[0].size(); ++j) {
                if (backtrack(board, visited, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, const string& s, int k) {
        if (!is_valid(board, i, j) || visited[i][j] || board[i][j] != s[k])
            return false;
        if (k == s.size()-1)
            return true;
        visited[i][j] = true;
        for (auto [x, y]: dirs) {
            if (backtrack(board, visited, i+x, j+y, s, k+1))
                return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool is_valid(vector<vector<char>>& board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
    array<pair<int, int>, 4> dirs;
};