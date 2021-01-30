#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    using int_pair = pair<int, int>;
    int minimumEffortPath(vector<vector<int>>& heights) {
        auto comp = [](int_pair x, int_pair y) {
            return x.first > y.first;
        };
        int m = heights.size();
        int n = heights[0].size();
        auto int2idx = [n](int x) { return int_pair(x / n, x % n); };
        auto idx2int = [n](int x, int y) { return x * n + y; };
        priority_queue<int_pair, vector<int_pair>, decltype(comp)> pq(comp);
        pq.emplace(0, 0);
        int br = m*n-1;
        vector<bool> seen(m * n, false);
        int ans = 0;
        while (!pq.empty()) {
            auto [k, coor] = pq.top();
            pq.pop();
            if (seen[coor]) {
                continue;
            }
            ans = max(ans, k);
            if (coor == br)
                break;
            seen[coor] = true;
            auto [x, y] = int2idx(coor);
            auto idx = idx2int(x-1, y);
            if (x > 0 && !seen[idx])
                pq.emplace(abs(heights[x][y] - heights[x-1][y]), idx);
            idx = idx2int(x+1, y);
            if (x < m-1 && !seen[idx])
                pq.emplace(abs(heights[x][y] - heights[x+1][y]), idx);
            idx = idx2int(x, y-1);
            if (y > 0 && !seen[idx])
                pq.emplace(abs(heights[x][y] - heights[x][y-1]), idx);
            idx = idx2int(x, y+1);
            if (y < n-1 && !seen[idx])
                pq.emplace(abs(heights[x][y] - heights[x][y+1]), idx);
        }
        return ans;
    }
};