#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = 0;
        int ans = 0;
        for (auto i = 0, j = 0; i != A.size(); ++i) {
            if (A[i] == 1) {
                ++n;
                ans = max(n, ans);
            }
            else {
                A[i] = 2;
                if (K > 0) {
                    --K;
                    ++n;
                    ans = max(n, ans);
                }
                else {
                    while (A[j] == 1)
                        ++j;
                    A[j] = 0;
                    ++j;
                    n = i - j + 1;
                }
            }
        }
        return ans;
    }
};