#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int cur = ans;
        for (auto i = 1; i <= k; ++i) {
            cur -= cardPoints[k - i] - cardPoints[n - i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
