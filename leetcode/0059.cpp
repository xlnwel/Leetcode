#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector ans(n, vector(n, 0));
        array dirs {
            make_pair(0, 1), make_pair(1, 0),
            make_pair(0, -1), make_pair(-1, 0)
        };
        int i = 0, j = -1;
        int idx = 0;
        int k = 0;
        while (true) {
            auto [x, y] = dirs[idx];
            if (is_valid(ans, i+x, j+y, n)) {
                while (is_valid(ans, i+x, j+y, n)) {
                    i += x;
                    j += y;
                    ans[i][j] = ++k;
                }
            }
            else
                break;
            idx = (idx + 1) % 4;
        }
        return ans;
    }
private:
    bool is_valid(vector<vector<int>>& m, int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n && m[i][j] == 0;
    }
};