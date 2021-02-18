#include <tuple>
#include <utility>
#include <vector>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        m = board.size();
        n = board[0].size();
        searched = vector<vector<bool>>(m, vector<bool>(n));
        for (auto i = 0; i != m; ++i) {
            for (auto j = 0; j != n; ++j) {
                if (searched[i][j])
                    continue;
                searched[i][j] = true;
                if (board[i][j] == 'O') {
                    bfs(i, j, board);
                }
            }
        }
    }
private:
    void bfs(int i, int j, vector<vector<char>>& board) {   // return true if the region connects to a boarder
        if (on_border(i, j))
            return;
        assert(board[i][j] == 'O');
        board[i][j] = 'X';
        vector<pair<int, int>> v{make_pair(i, j)};
        int x = i, y = j;
        int k = 0;
        while (k != v.size()) {
            tie(i, j) = v[k];
            while (true) {
                tie(x, y) = next(i, j, board);
                if (x >= m) {
                    break;
                }
                if (on_border(x, y)) {
                    x = m;
                    break;
                }
                assert(board[x][y] == 'O');
                board[x][y] = 'X';
                v.push_back({x, y});
            }
            if (x == m) {// i, j connects to a searched O or an O on the boarder
                for (auto [a, b]: v)
                    board[a][b] = 'O';
                break;
            }
            ++k;
        }
    }
    bool on_border(int i, int j) {
        return i == 0 || j == 0 || i == m-1 || j == n-1;
    }
    pair<int, int> next(int i, int j, vector<vector<char>>& board) {
        bool connect_to_searched_o = false; // return {m, 0} if (i, j) connects to a searched O
        if (i-1 >= 0 && board[i-1][j] == 'O') {
            if (!searched[i-1][j]) {
                searched[i-1][j] = true;
                return {i-1, j};
            }
            connect_to_searched_o = true;
        }
        else if (i+1 < m && board[i+1][j] == 'O') {
            if (!searched[i+1][j]) {
                searched[i+1][j] = true;
                return {i+1, j};
            }
            connect_to_searched_o = true;
        }
        else if (j-1 >= 0 && board[i][j-1] == 'O') {
            if (!searched[i][j-1]) {
                searched[i][j-1] = true;
                return {i, j-1};
            }
            connect_to_searched_o = true;
        }
        else if (j+1 < n && board[i][j+1] == 'O') {
            if (!searched[i][j+1]) {
                searched[i][j+1] = true;
                return {i, j+1};
            }
            connect_to_searched_o = true;
        }
        if (connect_to_searched_o)
            return {m, n};
        return {m+1, n};  // no next O
    }
    vector<vector<bool>> searched;
    int m, n;
};