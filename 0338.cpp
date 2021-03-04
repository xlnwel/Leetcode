#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector ans{0};
        while (ans.size() <= num) {
            int n = min(ans.size(), num+1 - ans.size());
            for (auto i = 0; i != n; ++i) {
                ans.push_back(ans[i] + 1);
            }
        }
        return ans;
    }
};