#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <map>

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
        auto idx2xy = [n](int x) { return int_pair(x / n, x % n); };
        auto xy2idx = [n](int x, int y) { return x * n + y; };
        priority_queue<int_pair, vector<int_pair>, decltype(comp)> pq(comp);
        pq.emplace(0, 0);
        int end = m*n-1;
        vector<bool> seen(m * n, false);
        constexpr array<pair<int, int>, 4> dirs = {
            make_pair(-1, 0),
            make_pair(1, 0),
            make_pair(0, -1),
            make_pair(0, 1),
        };
        while (!pq.empty()) {
            auto [k, coor] = pq.top();
            pq.pop();
            if (seen[coor]) {
                continue;
            }
            if (coor == end)
                return k;
            seen[coor] = true;
            auto [x, y] = idx2xy(coor);
            for (auto [i, j]: dirs) {
                i += x;
                j += y;
                auto idx_new = xy2idx(i, j);
                if (is_valid(i, j, m, n) && !seen[idx_new])
                    pq.emplace(max(k, abs(heights[x][y] - heights[i][j])), idx_new);
            }
        }
        return -1;
    }
private:
    bool is_valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


class Solution2 {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        auto idx2xy = [n](int idx) { return make_pair(idx / n, idx % n); };
        auto xy2idx = [n](int x, int y) { return x * n + y; };
        multimap<int, int> pq;
        pq.emplace(0, 0);
        auto end = m * n - 1;
        vector<bool> visited(m * n, false);
        constexpr array<pair<int, int>, 4> dirs = {
            make_pair(-1, 0),
            make_pair(1, 0),
            make_pair(0, -1),
            make_pair(0, 1),
        };
        while (!pq.empty()) {
            auto [k, idx] = *pq.begin();
            pq.erase(pq.begin());
            if (visited[idx])
                continue;
            if (idx == end)
                return k;
            visited[idx] = true;
            auto [x, y] = idx2xy(idx);
            for (auto [i, j]: dirs) {
                i += x;
                j += y;
                auto idx_new = xy2idx(i, j);
                if (is_valid(i, j, m, n) && !visited[idx_new])
                    pq.emplace(max(k, abs(heights[x][y] - heights[i][j])), idx_new);
            }
        }
        return -1;
    }
private:
    bool is_valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};