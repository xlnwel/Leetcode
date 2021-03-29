#include <vector>

using namespace std;


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans{0};
        int x = 1;
        for (auto i = 0; i != n; ++i) {
            for (int j = ans.size() - 1; j >=0; --j) {
                ans.emplace_back(ans[j] | x);
            }
            x <<= 1;
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> grayCode(int n) {
        int v = 0;
        helper(v, n);
        return ans;
    }
private:
    void helper(int& v, int i) {
        if (i == 0) {
            ans.push_back(v);
            return;
        }
        --i;
        helper(v, i);
        v = v ^ (1 << i);
        helper(v, i);
    }
    vector<int> ans;
};