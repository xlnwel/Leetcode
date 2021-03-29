#include <array>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        array<pair<int, int>, 4> dirs = {
            make_pair(-1, 0), 
            make_pair(1, 0), 
            make_pair(0, -1), 
            make_pair(0, 1), 
        };

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vector visited(m, vector(n, false));
        visited[0][0] = true;
        int ans = 0;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto [x, y]: dirs) {
                x += i;
                y += j;
                if (is_valid(x, y, m, n) && !visited[x][y] && is_valid2(x, y, k)) {
                    q.emplace(x, y);
                    visited[x][y] = true;
                }
            }
            ++ans;
        }
        return ans;
    }
private:
    bool is_valid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    bool is_valid2(int i, int j, int k) {
        int sum = 0;
        while (i) {
            sum += i % 10;
            i /= 10;
        }
        while (j) {
            sum += j % 10;
            j /= 10;
        }
        return sum <= k;
    }

};