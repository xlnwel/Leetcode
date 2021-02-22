#include <utility>
#include <array>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 2 || n < 2)
            return 0;
        vector visited(m, vector(n, false));
        auto cmp = [](pair<int, pair<int, int>>x, pair<int, pair<int, int>> y) {
            return x.first > y.first;
        };
        priority_queue<pair<int, pair<int, int>>, std::vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);
        for (auto i = 0; i != m-1; ++i) {
            pq.emplace(heightMap[i][0], make_pair(i, 0));
            pq.emplace(heightMap[i][n-1], make_pair(i, n-1));
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for (auto i = 1; i != n-1; ++i) {
            pq.emplace(heightMap[0][i], make_pair(0, i));
            pq.emplace(heightMap[m-1][i], make_pair(m-1, i));
            visited[0][i] = true;
            visited[m-1][i] = true;
        }

        int water = 0;
        int min_val = 0;
        array<pair<int, int>, 4> directions{make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
        while (!pq.empty()) {
            auto [k, p] = pq.top();
            auto [i, j] = p;
            pq.pop();
            min_val = max(heightMap[i][j], min_val);
            for (auto [x, y]: directions) {
                x = i + x;
                y = j + y;
                if (is_valid(x, y, m, n, visited)) {
                    pq.emplace(heightMap[x][y], make_pair(x, y));
                    if (min_val > heightMap[x][y])
                        water += min_val - heightMap[x][y];
                    visited[x][y] = true;
                }
            }
        }
        return water;
    }
private:
    bool is_valid(int i, int j, int m, int n, vector<vector<bool>>& visited) {
        return i > 0 && i < m-1 && j > 0 && j < n-1 && !visited[i][j];
    }
};