#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    using int_pair = pair<int, int>;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        auto int2idx = [n](int x) { return int_pair(x / n, x % n); };
        auto idx2int = [n](int x, int y) { return x*n+y; };
        auto comp = [](int_pair x, int_pair y) { return x.first > y.first; };
        priority_queue<int_pair, vector<int_pair>, decltype(comp)> pq(comp);
        pq.emplace(grid[0][0], 0);
        int br = n * n -1;
        vector<bool> visited(n * n, false);
        int ans = 0;
        while (!pq.empty()) {
            auto [k, coor] = pq.top();
            pq.pop();
            if (visited[coor])
                continue;
            visited[coor] = true;
            ans = max(ans, k);
            if (coor == br)
                break;
            auto [x, y] = int2idx(coor);
            int idx = idx2int(x-1, y);
            if (x > 0 && !visited[idx])
                pq.emplace(grid[x-1][y], idx);
            idx = idx2int(x+1, y);
            if (x < n-1 && !visited[idx])
                pq.emplace(grid[x+1][y], idx);
            idx = idx2int(x, y-1);
            if (y > 0 && !visited[idx])
                pq.emplace(grid[x][y-1], idx);
            idx = idx2int(x, y+1);
            if (y < n-1 && !visited[idx])
                pq.emplace(grid[x][y+1], idx);
        }
        return ans;
    }
};