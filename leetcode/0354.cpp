#include <vector>

using namespace std;


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[0] == y[0]? x[1] > y[1]: x[0] < y[0];
        });
        vector dp{envelopes[0][1]};
        for (auto x: envelopes) {
            if (x[1] > dp.back())
                dp.push_back(x[1]);
            else {
                auto itr = lower_bound(dp.begin(), dp.end(), x[1]);
                *itr = x[1];
            }
        }
        return dp.size();
    }
};


class Solution1 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto op = [](const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0];
        };
        sort(envelopes.begin(), envelopes.end(), op);
        vector dp(envelopes.size(), 1);
        int ans = 1;
        for (auto i = 1; i != envelopes.size(); ++i) {
            for (auto j = i-1; j >= 0; --j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1] && dp[j] >= dp[i]) {
                    dp[i] = dp[j] + 1;
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto op = [](const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0];
        };
        sort(envelopes.begin(), envelopes.end(), op);
        backtrack(envelopes.begin(), envelopes.end(), 0, 0, 0);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>::iterator beg, vector<vector<int>>::iterator end, int w, int h, int n) {
        for (auto itr = beg; itr != end; ++itr) {
            if (itr->at(0) > w && itr->at(1) > h) {
                backtrack(itr+1, end, itr->at(0), itr->at(1), n+1);
            }
        }
        ans = max(ans, n);
    }
    int ans = 0;
};
