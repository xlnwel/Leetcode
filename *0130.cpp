#include <tuple>
#include <utility>
#include <vector>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        m = board.size();
        n = board[0].size();
        searched = vector(m, vector(n, false));
        for (auto i = 0; i != m; ++i) {
            for (auto j = 0; j != n; ++j) {
                if (searched[i][j])
                    continue;
                searched[i][j] = true;
                if (board[i][j] == 'O' && !on_border(i, j))
                    bfs(i, j, board);
            }
        }
    }
private:
    void bfs(int i, int j, vector<vector<char>>& board) {
        assert(board[i][j] == 'O');
        board[i][j] = 'X';
        vector<pair<int, int>> v{{i, j}};
        int k = 0;
        int x = i, y = j;
        while (k != v.size()) {
            tie(i, j) = v[k];
            while (true) {
                tie(x, y) = next(i, j, board);
                if (y == n)
                    break;
                if (on_border(x, y)) {
                    x = m;
                    break;
                }
                assert(board[x][y] == 'O');
                board[x][y] = 'X';
                v.emplace_back(x, y);
            }
            if (x == m) {
                for (auto [a, b]: v) {
                    board[a][b] = 'O';
                }
                return;
            }
            ++k;
        }
    }
    bool on_border(int i, int j) {
        return i == 0 || j == 0 || i == m-1 || j == n-1;
    }
    pair<int, int> next(int i, int j, vector<vector<char>>& board) {
        bool connect_to_searched_o = false;
        if (i-1 >= 0 && board[i-1][j] == 'O') {
            if (searched[i-1][j])
                connect_to_searched_o = true;
            else {
                searched[i-1][j] = true;
                return {i-1, j};
            }
        }
        if (i+1 < m && board[i+1][j] == 'O') {
            if (searched[i+1][j])
                connect_to_searched_o = true;
            else {
                searched[i+1][j] = true;
                return {i+1, j};
            }
        }
        if (j-1 >= 0 && board[i][j-1] == 'O') {
            if (searched[i][j-1])
                connect_to_searched_o = true;
            else {
                searched[i][j-1] = true;
                return {i, j-1};
            }
        }
        if (j+1 < n && board[i][j+1] == 'O') {
            if (searched[i][j+1])
                connect_to_searched_o = true;
            else {
                searched[i][j+1] = true;
                return {i, j+1};
            }
        }
        if (connect_to_searched_o)
            return {m, n};  // first = m indicates that (i,j) connects to a searched O, second = n indicates there is no next either because there is no next or because reaching a node on the boder
        return {m+1, n};
    }
    int m, n;
    vector<vector<bool>> searched;
};