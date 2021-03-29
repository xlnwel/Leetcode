#include <tuple>
#include <utility>
#include <array>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        array<pair<int, int>, 4> dirs = {
            make_pair(-1, 0), 
            make_pair(1, 0), 
            make_pair(0, -1), 
            make_pair(0, 1), 
        };
        int m = board.size();
        int n = board[0].size();
        for (auto i = 0; i != m; ++i) {
            if (board[i][0] == 'O')
                dfs(board, i, 0, dirs);
            if (board[i][n-1] == 'O')
                dfs(board, i, n-1, dirs);
        }
        for (auto i = 0; i != n; ++i) {
            if (board[0][i] == 'O')
                dfs(board, 0, i, dirs);
            if (board[m-1][i] == 'O')
                dfs(board, m-1, i, dirs);
        }
        for (auto i = 0; i != m; ++i) {
            for (auto j = 0; j != n; ++j) {
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j, const array<pair<int, int>, 4>& dirs) {
        stack<pair<int, int>> s;
        s.emplace(i, j);
        while (!s.empty()) {
            auto [x, y] = s.top();
            board[x][y] = 'Y';
            s.pop();
            for (auto [m, n]: dirs) {
                i = x + m;
                j = y + n;
                if (is_valid(board, i, j))
                    s.emplace(i, j);
            }
        }
    }
    bool is_valid(const vector<vector<char>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[i].size() && board[i][j] == 'O';
    }
};


class Solution2 {
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